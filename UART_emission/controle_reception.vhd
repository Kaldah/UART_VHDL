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
    signal start_detected : std_logic := '0';
begin
    process(tmpclk, reset)
    begin
        if reset = '1' then
            bit_count <= 0;
            start_detected <= '0';
            Ferr <= '0';
            DRdy <= '0';
        elsif rising_edge(tmpclk) then
            if start_detected = '0' then
                if tmprxd = '0' then  -- Start bit detected
                    start_detected <= '1';
                    bit_count <= 0;
                end if;
            else
                if bit_count < 8 then
                    received_data(bit_count) <= tmprxd;
                    bit_count <= bit_count + 1;
                else
                    if tmprxd = '1' then  -- Stop bit
                        DRdy <= '1';
                    else
                        Ferr <= '1';
                    end if;
                    start_detected <= '0';
                end if;
            end if;
        end if;
    end process;

    data <= received_data;
    OErr <= '0';  -- To be handled based on specific conditions
end Behavioral;
