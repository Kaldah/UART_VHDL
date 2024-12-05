----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:19:00 12/19/2023 
-- Design Name: 
-- Module Name:    RxUnit - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity RxUnit is
port ( clk, reset : in std_logic ;
       enable : in std_logic ;
       read : in std_logic ;
       rxd : in std_logic ;
       data : out std_logic_vector(7 downto 0) ;
       FErr, OErr, DRdy : out std_logic );
end RxUnit ;

architecture Behavioral of RxUnit is

    component EltInstants is
        port(enable : in std_logic;
            reset : in std_logic;
            Rxd : in std_logic;
            DRdy : in std_logic;
            tmpClk : out std_logic;
            tmpRxd : out std_logic
        );
    end component;

    component EltEtat is
        port (
            reset : in std_logic;
            clk : in std_logic;
            tmpClk : in std_logic;
            tmpRxd : in std_logic;
            read : in std_logic;
            FErr : out std_logic;
            OErr : out std_logic;
            DRdy : out std_logic;
            data : out std_logic_vector(7 downto 0));
    end component;

    signal tmpClk, tmpRxd, DRdy_bis : std_logic;

begin

    instants : EltInstants 
    port map(
        enable => enable, 
        reset => reset, 
        Rxd => rxd, 
        DRdy => DRdy_bis, 
        tmpClk => tmpClk, 
        tmpRxd => tmpRxd);

    etat : EltEtat 
    port map(
        reset => reset, 
        clk => clk, 
        tmpClk => tmpClk, 
        tmpRxd => tmpRxd, 
        read => read, 
        FErr => FErr, 
        OErr => OErr, 
        DRdy => DRdy_bis,
        data => data);


end Behavioral;

