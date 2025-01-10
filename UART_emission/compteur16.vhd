entity Compteur16 is
    Port (
        clk : in std_logic;
        reset : in std_logic;
        enable : in std_logic;
        tmpclk : out std_logic;
        tmprxd : out std_logic
    );
end Compteur16;

architecture Behavioral of Compteur16 is
    signal count : integer range 0 to 15 := 0;
    signal tmpclk_reg : std_logic := '0';
begin
    process(clk, reset)
    begin
        if reset = '1' then
            count <= 0;
            tmpclk_reg <= '0';
        elsif rising_edge(clk) then
            if enable = '1' then
                if count = 15 then
                    count <= 0;
                    tmpclk_reg <= not tmpclk_reg;
                else
                    count <= count + 1;
                end if;
            end if;
        end if;
    end process;

    tmpclk <= tmpclk_reg;
    -- tmprxd should be connected based on the specific RxD signal handling
end Behavioral;
