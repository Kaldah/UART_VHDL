--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:05:45 01/19/2024
-- Design Name:   
-- Module Name:   /home/gaut/.Xilinx/UartTest/RxTester.vhd
-- Project Name:  UartTest
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: RxUnit
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
 
ENTITY RxTester IS
END RxTester;
 
ARCHITECTURE behavior OF RxTester IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT RxUnit
    PORT(
         clk : IN  std_logic;
         reset : IN  std_logic;
         enable : IN  std_logic;
         read : IN  std_logic;
         rxd : IN  std_logic;
         data : OUT  std_logic_vector(7 downto 0);
         FErr : OUT  std_logic;
         OErr : OUT  std_logic;
         DRdy : OUT  std_logic
        );
    END COMPONENT;

   
   component clkUnit
    port (
      clk, reset : in std_logic;
      enableTX   : out std_logic;
      enableRX   : out std_logic
    );
  end component;
    
   -- clocks
   signal enableTX : std_logic;
   signal enableRX : std_logic;

   --Inputs
   signal clk : std_logic := '0';
   signal reset : std_logic := '0';
   signal enable : std_logic := '0';
	-- On supposera qu'on lis toujours correctement 
   signal read : std_logic := '1';
   signal rxd : std_logic := '0';

 	--Outputs
   signal data : std_logic_vector(7 downto 0);
   signal FErr : std_logic;
   signal OErr : std_logic;
   signal DRdy : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: RxUnit PORT MAP (
          clk => clk,
          reset => reset,
          enable => enableRx,
          read => read,
          rxd => rxd,
          data => data,
          FErr => FErr,
          OErr => OErr,
          DRdy => DRdy
        );


   clkUnit_inst : clkUnit
  port map(
    clk      => clk,
    reset    => reset,
    enableTX => enableTX,
    enableRX => enableRX
  );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   variable data : std_logic_vector(7 downto 0);

   begin		
		
	
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      reset <= '1';

      ----- Premier test ----------

      -- Idle 
      rxd <= '1';
      wait until enableTX = '1';

      -- Start bit
      rxd <= '0';
      wait until enableTX = '0';

      -- Data
      data := "10111101";
      for i in 7 downto 0 loop
         wait until enableTX = '1';
        rxd <= data(i);
        wait until enableTX = '0';
      end loop;
      wait until enableTX = '1';

      -- Stop bit
      rxd <= '1';
      wait until enableTX = '0';

      ----- Deuxieme test ----------

      wait for clk_period*10;

      -- Idle

      rxd <= '1';
      wait until enableTX = '1';

      -- Start bit

      rxd <= '0';
      wait until enableTX = '0';

      -- Data

      data := "11101111";
      for i in 0 to 7 loop
         wait until enableTX = '1';
        rxd <= data(i);
        wait until enableTX = '0';
      end loop;

      wait until enableTX = '1';

      -- Stop bit

      rxd <= '1';
      wait until enableTX = '0';

      -- insert stimulus here 

      wait;
   end process;

END;
