library IEEE;
use IEEE.std_logic_1164.all;

entity clkUnit is
  
 port (
   clk, reset : in  std_logic;
   enableTX   : out std_logic;
   enableRX   : out std_logic);
    
end clkUnit;

architecture behavorial of clkUnit is

  component diviseurClk1Hz is
    port (
      clk, reset : in  std_logic;
      nclk       : out std_logic);
  end component;

begin

div_clk: diviseurClk1Hz 
  generic map(facteur => 16)
  port map(
    clk=>clk, 
    reset=>reset, 
    nclk=>enableTX
    );
  enableRX<=clk;

end behavorial;
