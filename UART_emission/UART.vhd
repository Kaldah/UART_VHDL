library IEEE;
use IEEE.std_logic_1164.all;

entity UARTunit is
  port (
    clk, reset : in  std_logic;
    cs, rd, wr : in  std_logic;
    RxD        : in  std_logic;
    TxD        : out std_logic;
    IntR, IntT : out std_logic;         
    addr       : in  std_logic_vector(1 downto 0);
    data_in    : in  std_logic_vector(7 downto 0);
    data_out   : out std_logic_vector(7 downto 0));
end UARTunit;


architecture UARTunit_arch of UARTunit is

  -- a completer avec l'interface des differents composants
  -- de l'UART
  -- LES 4 COMPOSANTS

  COMPONENT TxUnit
  PORT(
    clk, reset : IN  std_logic;
    enable : IN  std_logic;
    ld : IN  std_logic;
    txd : OUT  std_logic;
    regE : OUT  std_logic;
    bufE : OUT  std_logic;
    data : IN  std_logic_vector(7 downto 0)
  );
  END COMPONENT;

  COMPONENT RxUnit_4
  PORT(
    clk, reset : IN  std_logic;
    enable : IN  std_logic;
    read : IN  std_logic;
    rxd : IN  std_logic;
    data : OUT std_logic_vector(7 downto 0);
    Ferr, OErr, DRdy : OUT std_logic
  );
  END COMPONENT;

  COMPONENT clkUnit
  PORT(
    clk : IN  std_logic;
    reset : IN  std_logic;
    enableTX : OUT  std_logic;
    enableRX : OUT  std_logic
  );
  END COMPONENT;

  COMPONENT ctrlUnit  
  PORT(
    clk, reset : IN  std_logic;
    rd, cs : IN  std_logic;
    DRdy, FErr, OErr: IN  std_logic;
    BufE, RegE : IN std_logic;
    IntR, IntT : OUT std_logic;
    ctrlReg : OUT std_logic_vector(7 downto 0)
  );
  END COMPONENT;

  signal lecture, ecriture : std_logic;
  signal donnees_recues : std_logic_vector(7 downto 0);
  signal registre_controle : std_logic_vector(7 downto 0);

  -- a completer par les signaux internes manquants
  
  
  signal buf : std_logic;
  signal reg : std_logic;
  signal Ferr, OErr, DRdy : std_logic;
  signal enableTX, enableRX : std_logic;

  begin  -- UARTunit_arch

    lecture <= '1' when cs = '0' and rd = '0' else '0';
    ecriture <= '1' when cs = '0' and wr = '0' else '0';
    data_out <= donnees_recues when lecture = '1' and addr = "00"
                else registre_controle when lecture = '1' and addr = "01"
                else "00000000";
  
    -- a completer par la connexion des differents composants
    
    clk_unit: clkUnit PORT MAP (
      clk => clk,
      reset => reset,
      enableTX => enableTX,
      enableRX => enableRX
    );
    

    Tx: TxUnit PORT MAP (
      clk => clk,
      reset => reset,
      enable => enableTX,
      ld => ecriture,
      txd => TxD,
      regE => reg,
      bufE => buf,
      data => data_in
    );

    Rx: RxUnit_4 PORT MAP (
      clk => clk,
      reset => reset,
      enable => enableRX,
      read => lecture,
      rxd => RxD,
      data => donnees_recues,
      Ferr => Ferr,
      OErr => OErr,
      DRdy => DRdy
    );

    control_unit: ctrlUnit PORT MAP (
      clk => clk,
      reset => reset,
      rd => rd,
      cs => cs,
      DRdy => DRdy,
      FErr => Ferr,
      OErr => OErr,
      BufE => buf,
      RegE => reg,
      IntR => IntR,
      IntT => IntT,
      ctrlReg => registre_controle
    );

  end UARTunit_arch;
