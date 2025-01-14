library IEEE;
use IEEE.std_logic_1164.all;

entity Compteur16 is
    Port (
        clk : in std_logic;
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
    signal counter_trames : integer range 0 to 10 := 0;

begin
    process(clk, reset)
    begin
        if reset = '0' then
            count <= 0;
            tmpclk <= '0';
            tmprxd <= '1';
            etat <= repos;
        elsif rising_edge(clk) then
            case etat is
                when repos =>
                    if enable = '1' then
                        if RxD = '0' then
                            etat <= count8;
                        end if;
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
                        tmpclk <= RxD;
                        tmpclk <= RxD;
                        count <= 0;
                        counter_trames <= counter_trames + 1;
                    end if;
                    if counter_trames = 10 then
                        counter_trames <= 0;
                        etat <= repos;
                    end if;
            end case;
        end if;
    end process;
end Behavioral;
