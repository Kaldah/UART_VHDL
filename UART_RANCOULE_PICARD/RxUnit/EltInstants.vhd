----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:29:27 12/19/2023 
-- Design Name: 
-- Module Name:    EltInstants - Behavioral 
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

entity EltInstants is
    port(enable : in std_logic;
        reset : in std_logic;
        Rxd : in std_logic;
		  DRdy : in std_logic;
        tmpClk : out std_logic;
        tmpRxd : out std_logic
    );
end EltInstants;

architecture Behavioral of EltInstants is

type t_etat is (init, cpt8, cpt16, fin); -- Etats possibles du composant
signal saveTmpClk : std_logic;

begin
	process (enable, reset)
	variable etat : t_etat; -- Etat actuel du composant
	variable saveRxd : std_logic; -- Sauvegarde de la valeur de Rxd
	variable cpt : natural; -- Compteur de cycles enable
    
  begin 
    -- Réinitialisation du composant
    if reset = '0' then
        etat := init;
     
    elsif rising_edge(enable) then
        case etat is
            -- Etat d'initialisation
            when init => 
                -- Initialisation du compteur, du bit de stop et de la clock
                cpt := 0;
                tmpClk <= '0';
					 saveTmpClk <= '0';
                -- Vérification du début de la réception
                if Rxd = saveRxd then
                    etat := init;
                else
                    etat := cpt8;
                end if;

            -- Attente de 8 cycles
            when cpt8 =>
            if cpt >= 8 then
                cpt := 0;
                etat := cpt16;
            else
                -- Incrémentation du compteur
                cpt := cpt + 1;
            end if;
            
            -- Attente de 16 cycles
            when cpt16 =>
            if cpt >= 16 then
                cpt := 0;
                -- Vérification de la réception complète
                if DRdy = '1' then
                    etat := fin;
                else
                    -- Alternance du signal d'horloge tmpClk 
                    if saveTmpClk = '1' then
								saveTmpClk <= '0';
                        tmpClk <= '0';
                    else
								saveTmpClk <= '1';
                        tmpClk <= '1';
                    end if;

                    tmpRxd <= Rxd;

                    -- Recontage de 16 cycles enable
                    etat := cpt16;
                end if;
            else
                -- Incrémentation du compteur
                cpt := cpt + 1;
            end if; 
                
            -- Fin de l'opération
            when fin =>
            tmpRxd <= '0';
        end case;
    end if;
  end process;

end Behavioral;

