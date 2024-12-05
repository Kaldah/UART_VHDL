--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:09:49 10/31/2018
-- Design Name:   
-- Module Name:   testTxUnit.vhd
-- Project Name:  uart
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: TxUnit
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;

ENTITY testTxUnit IS
END testTxUnit;

ARCHITECTURE behavior OF testTxUnit IS

  -- Component Declaration for the Unit Under Test (UUT)

  COMPONENT TxUnit
    PORT (
      clk : IN STD_LOGIC;
      reset : IN STD_LOGIC;
      enable : IN STD_LOGIC;
      ld : IN STD_LOGIC;
      txd : OUT STD_LOGIC;
      regE : OUT STD_LOGIC;
      bufE : OUT STD_LOGIC;
      data : IN STD_LOGIC_VECTOR(7 DOWNTO 0)
    );
  END COMPONENT;

  COMPONENT clkUnit
    PORT (
      clk : IN STD_LOGIC;
      reset : IN STD_LOGIC;
      enableTX : OUT STD_LOGIC;
      enableRX : OUT STD_LOGIC
    );
  END COMPONENT;

  SIGNAL clk : STD_LOGIC := '0';
  SIGNAL reset : STD_LOGIC := '0';
  SIGNAL enableTx : STD_LOGIC := '0';
  SIGNAL enableRx : STD_LOGIC := '0';
  SIGNAL ld : STD_LOGIC := '0';
  SIGNAL data : STD_LOGIC_VECTOR(7 DOWNTO 0) := (OTHERS => '0');

  SIGNAL txd : STD_LOGIC;
  SIGNAL regE : STD_LOGIC;
  SIGNAL bufE : STD_LOGIC;

  -- Clock period definitions
  CONSTANT clk_period : TIME := 10 ns;

BEGIN

  -- Instantiate the Unit Under Test
  uut0 : TxUnit PORT MAP(
    clk => clk,
    reset => reset,
    enable => enableTX,
    ld => ld,
    txd => txd,
    regE => regE,
    bufE => bufE,
    data => data
  );

  -- Instantiate the clkUnit
  clkUnit1 : clkUnit PORT MAP(
    clk => clk,
    reset => reset,
    enableTX => enableTX,
    enableRX => enableRX
  );

  -- Clock process definitions
  clk_process : PROCESS
  BEGIN
    clk <= '0';
    WAIT FOR clk_period/2;
    clk <= '1';
    WAIT FOR clk_period/2;
  END PROCESS;
  -- Stimulus process
  stim_proc : PROCESS
  BEGIN
    -- maintien du reset durant 100 ns.
    WAIT FOR 100 ns;
    reset <= '1';

    WAIT FOR 200 ns;

    -- l'émetteur est dispo ?
    IF NOT (regE = '1' AND bufE = '1') THEN
      WAIT UNTIL regE = '1' AND bufE = '1';
    END IF;

    -- si oui, on charge la donnée
    WAIT FOR clk_period;
    -- émission du caractère 0x55
    data <= "01010101";
    ld <= '1';

    -- on attend de voir que l'ordre d'émission
    -- a été bien pris en compte avant de rabaisser
    -- le signal ld
    IF NOT (regE = '1' AND bufE = '0') THEN
      WAIT UNTIL regE = '1' AND bufE = '0';
    END IF;
    WAIT FOR clk_period;
    ld <= '0';

    ----------------------------------------------------------------------------------------------------------

    -- compléter avec des tests qui montrent que la prise en compte de la demande d'émission
    -- d'un autre caractère se fait lorsqu'on émet un caractère et ceci quelque soit
    -- l'étape d'émission
    WAIT FOR 2000 ns;

    reset <= '0';

    WAIT FOR 100 ns;
    reset <= '1';

    WAIT FOR 200 ns;

    -- l'émetteur est dispo ?
    IF NOT (regE = '1' AND bufE = '1') THEN
      WAIT UNTIL regE = '1' AND bufE = '1';
    END IF;

    -- si oui, on charge la donnée
    WAIT FOR clk_period;
    -- émission du caractère 0x55
    data <= "01010101";
    ld <= '1';

    -- on attend de voir que l'ordre d'émission
    -- a été bien pris en compte avant de rabaisser
    -- le signal ld
    IF NOT (regE = '1' AND bufE = '0') THEN
      WAIT UNTIL regE = '1' AND bufE = '0';
    END IF;
    WAIT FOR clk_period;
    ld <= '0';

    IF NOT (regE = '0' AND bufE = '1') THEN
      WAIT UNTIL regE = '0' AND bufE = '1';
    END IF;

    WAIT FOR clk_period;

    data <= "11111111";
    WAIT FOR clk_period;
    ld <= '1';
    WAIT FOR clk_period;
    ld <= '0';


    ------------------------------------------------------------------------------------------------

    WAIT FOR 5000 ns;

    reset <= '0';

    WAIT FOR 100 ns;
    reset <= '1';

    WAIT FOR 200 ns;

    -- l'émetteur est dispo ?
    IF NOT (regE = '1' AND bufE = '1') THEN
      WAIT UNTIL regE = '1' AND bufE = '1';
    END IF;

    -- si oui, on charge la donnée
    WAIT FOR clk_period;
    -- émission du caractère 0x55
    data <= "01010101";
    ld <= '1';

    -- on attend de voir que l'ordre d'émission
    -- a été bien pris en compte avant de rabaisser
    -- le signal ld
    IF NOT (regE = '1' AND bufE = '0') THEN
      WAIT UNTIL regE = '1' AND bufE = '0';
    END IF;
    WAIT FOR clk_period;
    ld <= '0';

    IF NOT (regE = '0' AND bufE = '1') THEN
      WAIT UNTIL regE = '0' AND bufE = '1';
    END IF;

    WAIT FOR clk_period;

    data <= "11111111";
    WAIT FOR clk_period;
    ld <= '1';
    WAIT FOR clk_period;
    ld <= '0';

    WAIT FOR clk_period * 10;
    

    data <= "11101111";
    WAIT FOR clk_period;
    ld <= '1';
    WAIT FOR clk_period;
    ld <= '0';

    WAIT;

  END PROCESS;

END;