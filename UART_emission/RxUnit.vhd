entity RxUnit is
  Port (
      clk : in std_logic;
      reset : in std_logic;
      enable : in std_logic;
      rd : in std_logic;
      rxd : in std_logic;
      data : out std_logic_vector(7 downto 0);
      Ferr : out std_logic;
      OErr : out std_logic;
      DRdy : out std_logic
  );
end RxUnit;

architecture Behavioral of RxUnit is
  signal tmpclk : std_logic;
  signal tmprxd : std_logic;
begin
  u_compteur16 : Compteur16
      port map (
          clk => clk,
          reset => reset,
          enable => enable,
          tmpclk => tmpclk,
          tmprxd => rxd  -- Direct connection for simplicity
      );

  u_controleReception : ControleReception
      port map (
          clk => clk,
          reset => reset,
          tmpclk => tmpclk,
          tmprxd => rxd,  -- Direct connection for simplicity
          data => data,
          Ferr => Ferr,
          OErr => OErr,
          DRdy => DRdy
      );
end Behavioral;
