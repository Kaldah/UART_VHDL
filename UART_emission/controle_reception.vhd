library IEEE;
use IEEE.std_logic_1164.all;

entity ControleReception is
    Port (
        clk : in std_logic;
        reset : in std_logic;
        tmprxd : in std_logic;
        tmpclk : in std_logic;
        read : in std_logic;
        data : out std_logic_vector(7 downto 0);
        Ferr : out std_logic;
        OErr : out std_logic;
        DRdy : out std_logic
    );
end ControleReception;

architecture Behavioral of ControleReception is
    signal received_data : std_logic_vector(7 downto 0) := (others => '0');
    signal bit_count : integer range 0 to 8 := 0;

    type t_etat is (repos, reception, transfert);
    signal etat : t_etat := repos;
begin

    process(clk, reset)
    begin
        if reset= '0' then
            received_data <= (others => '0');
            bit_count <= 0;
            Ferr <= '0';
            OErr <= '0';
            DRdy <= '0';
            etat <= repos;
        elsif rising_edge(clk) then
            case etat is 
                when repos => 
                    if read = '1' then
                        if tmpclk = '1' and tmprxd = '0' then
                            etat <= reception;
                        end if;
                    end if;
                when reception =>
                    if tmpclk = '0' then
                        if bit_count < 8 then
                            received_data(bit_count) <= tmprxd;
                            bit_count <= bit_count + 1;
                        elsif bit_count = 8 then
                                etat <= transfert;
                        end if;
                    end if;
                when transfert =>
                    DRdy <= '0';
                    if read = '0'then
                        OErr <= '1';
                    end if;
                    etat <= repos;

                    

            end case;
        end if;
    

    end process;

end Behavioral;
