library IEEE;
use IEEE.std_logic_1164.all;

entity Compteur16 is
    Port (
        reset : in std_logic;
        RxD : in std_logic;
        enable : in std_logic;
        tmpclk : out std_logic;
        tmprxd : out std_logic
    );
end Compteur16;

architecture Behavioral of Compteur16 is
    signal count : integer range 0 to 15 := 0;

    type t_etat is (repos, count8, count16);
    signal etat : t_etat := repos;
    signal counter_bits : integer range 0 to 10 := 0;

begin
    process(enable, reset)
    begin
        if reset = '0' then
            count <= 0;
            tmpclk <= '0';
            tmprxd <= '0';
            etat <= repos;
        elsif rising_edge(enable) then
            case etat is
                when repos =>
                    count <= 0;
                    tmpclk <= '0';
                    tmprxd <= '0';
                    if RxD = '0' then
                        etat <= count8;
                    end if;
                when count8 =>
                    count <= count + 1;
                    if count = 7 then
                        tmpclk <= '1';
                        tmprxd <= RxD;
                        count <= 0;
                        etat <= count16;
                    end if;
                when count16 =>
                    count <= count + 1;
                    
                    if count = 15 then
                        tmprxd <= RxD;
                        tmpclk <= '1';
                        count <= 0;
                        -- 11 bits bits
                        if counter_bits = 10 then
                            counter_bits <= 0;
                            etat <= repos;
                        else
                            counter_bits <= counter_bits + 1;
                        end if;
                    else
                        tmpclk <= '0';
                    end if;
            end case;
        end if;
    end process;
end Behavioral;
