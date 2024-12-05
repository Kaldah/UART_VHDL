----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:30:11 12/19/2023 
-- Design Name: 
-- Module Name:    EltEtat - Behavioral 
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

entity EltEtat is
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
end EltEtat;

architecture Behavioral of EltEtat is

type etat_type is (init, assemblage, fin, finy);
signal etat : etat_type := init;
signal saveData : std_logic_vector(7 downto 0) ;

begin
    process(clk, reset, tmpClk)
	 variable compteur : integer range 0 to 7 := 0;
    
    begin 
      -- Réinitialisation du composant
      if reset = '0' then
          etat <= init;
       
      elsif rising_edge(tmpClk) then
          case etat is
              -- Etat d'initialisation
            when init => 
              etat <= assemblage;

              -- Assemblage des 8 bits de données
              when assemblage =>
              if compteur = 7 then
                compteur := 0;
                etat <= fin;
              else
                -- Sauvegarde des données
                saveData(compteur) <= tmpRxd;
                compteur := compteur + 1;
                etat <= assemblage;
              end if;

              -- Fin de la réception des 8 bits de données
              when fin =>
                -- Détection de l'erreur de parité
                if tmpRxd = '0' then
                    FErr <= '1';
                else 
                    DRdy <= '1';
                    data <= saveData;
                    -- Détection de l'erreur de donnée
                    if read = '0' then
                        OErr <= '1';
                    end if;
                    etat <= finy;
                end if; 
               
              -- Réinitialisation de DRdy  
              when finy =>
                if rising_edge(clk) then
                    DRdy <= '0';
                end if;
                etat <= init;
              
          end case;
      end if;
    end process;

end Behavioral;

