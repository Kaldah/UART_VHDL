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
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

ENTITY EltInstants IS
    PORT (
        enable : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        Rxd : IN STD_LOGIC;
        tmpClk : OUT STD_LOGIC;
        tmpRxd : OUT STD_LOGIC
    );
END EltInstants;

ARCHITECTURE Behavioral OF EltInstants IS

    TYPE t_etat IS (init, cpt8, cpt16); -- Etats possibles du composant
    SIGNAL saveTmpClk : STD_LOGIC;
    SIGNAL etat : t_etat; -- Etat actuel du composant

BEGIN
    PROCESS (enable, reset)

        VARIABLE cpt : NATURAL; -- Compteur de cycles enable
        VARIABLE cpt_bit : NATURAL; -- Compteur de bits

    BEGIN
        -- Réinitialisation du composant
        IF reset = '0' THEN
            etat <= init;
            cpt := 0;
            cpt_bit := 0;

        ELSIF rising_edge(enable) THEN
            CASE etat IS
                    -- Etat d'initialisation
                WHEN init =>
                    tmpClk <= '0';
                    saveTmpClk <= '0';


                    -- Vérification du début de la réception
                    IF Rxd = '0' THEN
                        -- Initialisation du compteur, du bit de stop et de la clock
                        cpt := 0;
                        tmpClk <= '0';
                        saveTmpClk <= '0';
                        cpt_bit := 0;
                        etat <= cpt8;
                    END IF;

                    -- Attente de 8 cycles
                WHEN cpt8 =>
                    IF cpt >= 7 THEN
                        tmpClk <= '1';
                        saveTmpClk <= '1';
                        tmpRxd <= Rxd;
                        cpt := 0;
                        etat <= cpt16;
                    ELSE
                        -- Incrémentation du compteur
                        cpt := cpt + 1;
                    END IF;

                    -- Attente de 16 cycles
                WHEN cpt16 =>
                    tmpClk <= '0';

                    IF cpt = 15 THEN
                        
                        cpt := 0;
                        -- Vérification de la réception complète

                        tmpRxd <= Rxd;

                        saveTmpClk <= '1';
                        tmpClk <= '1';

                        IF cpt_bit = 8 THEN
                            tmpRxd <= '1';
                            etat <= init;
                        END IF;

                        cpt_bit := cpt_bit + 1;

                    ELSE
                        -- Incrémentation du compteur
                        cpt := cpt + 1;
                    END IF;

            END CASE;
        END IF;
    END PROCESS;

END Behavioral;