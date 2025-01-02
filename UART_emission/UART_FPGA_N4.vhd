library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity UART_FPGA_N4 is
  port (
  -- ne garder que les ports utiles ?
    -- les 16 switchs
    swt : in std_logic_vector (15 downto 0);
    -- les 5 boutons noirs
    btnC, btnU, btnL, btnR, btnD : in std_logic;
    -- horloge
    mclk : in std_logic;
    -- les 16 leds
    led : out std_logic_vector (15 downto 0);
    -- les anodes pour sélectionner les afficheurs 7 segments à utiliser
    an : out std_logic_vector (7 downto 0);
    -- valeur affichée sur les 7 segments (point décimal compris, segment 7)
    ssg : out std_logic_vector (7 downto 0)
    -- ligne série (à rajouter)
    RxD : in std_logic;
    TxD : out std_logic

  );
end UART_FPGA_N4;

architecture synthesis of UART_FPGA_N4 is

  -- rappel du (des) composant(s)
  -- À COMPLÉTER 

  COMPONENT UARTunit
  PORT(
    clk, reset : IN  std_logic;
    cs, rd, wr : IN  std_logic;
    RxD        : IN  std_logic;
    TxD        : OUT std_logic;
    IntR, IntT : OUT std_logic;         
    addr       : IN  std_logic_vector(1 downto 0);
    data_in    : IN  std_logic_vector(7 downto 0);
    data_out   : OUT std_logic_vector(7 downto 0)
  );
  END COMPONENT;

  COMPONENT diviseurClk
  PORT(
    clk, reset : IN  std_logic;
    nclk       : OUT std_logic
  );
  END COMPONENT;

  COMPONENT echoUnit
  PORT(
    clk, reset : IN  std_logic;
    cs, rd, wr: OUT std_logic;
    IntR, IntT : IN std_logic;
    addr : IN  std_logic_vector(1 downto 0);
    data_in : IN  std_logic_vector(7 downto 0);
    data_out : out  std_logic_vector(7 downto 0);
  );
  END COMPONENT;

  signal newclk : std_logic;
  signal passageIntR : std_logic;
  signal passageIntT : std_logic;
  signal passagecs, passagerd, passagewr : std_logic;
  signal passageaddr : std_logic_vector(1 downto 0);
  signal passagead1 : std_logic_vector(7 downto 0);
  signal passagead2 : std_logic_vector(7 downto 0);

begin

  -- instanciation du (des) composant(s)


  


  divUnit_inst : diviseurClk
  PORT MAP(
    clk => mclk,
    reset => not btnC,
    nclk => newclk
  );

  UARTunit_inst : UARTunit
  PORT MAP(
    clk => mclk,
    reset => btnC,
    cs => passagecs,
    rd => passagerd,
    wr => passagewr,
    RxD => RxD,
    TxD => TxD,
    IntR => passageIntR,
    IntT => passageIntT,
    addr => passageaddr,
    data_in => passagead2,
    data_out => passagead1
  );

  echoUnit_inst : echoUnit
  PORT MAP(
    clk => newclk,
    reset => not btnC,
    addr => passageaddr,
    data_in => passagead1,
    data_out => passagead2,
    cs => passagecs,
    rd => passagerd,
    wr => passagewr,
    IntR => passageIntR,
    IntT => passageIntT
  );

  -- valeurs des sorties (à modifier)

  -- convention afficheur 7 segments 0 => allumé, 1 => éteint
  ssg <= (others => '1');
  -- aucun afficheur sélectionné
  an(7 downto 0) <= (others => '1');
  -- 16 leds éteintes
  led(15 downto 0) <= (others => '0');

  -- connexion du (des) composant(s) avec les ports de la carte
  -- À COMPLÉTER 
    
end synthesis;
