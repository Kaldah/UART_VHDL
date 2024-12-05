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
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

ENTITY EltEtat IS
  PORT (
    reset : IN STD_LOGIC;
    clk : IN STD_LOGIC;
    tmpClk : IN STD_LOGIC;
    tmpRxd : IN STD_LOGIC;
    read : IN STD_LOGIC;
    FErr : OUT STD_LOGIC;
    OErr : OUT STD_LOGIC;
    DRdy : OUT STD_LOGIC;
    data : OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
END EltEtat;

ARCHITECTURE Behavioral OF EltEtat IS

  TYPE etat_type IS (init, assemblage, fin, finy);
  SIGNAL etat : etat_type := init;
  SIGNAL saveData : STD_LOGIC_VECTOR(7 DOWNTO 0);

BEGIN
  PROCESS (clk, reset, tmpClk)
    VARIABLE compteur : INTEGER RANGE 0 TO 7 := 0;
    VARIABLE compteur_ready : INTEGER RANGE 0 TO 2 := 0;

  BEGIN
    -- Réinitialisation du composant
    IF reset = '0' THEN
      etat <= init;
      data <= (OTHERS => '0');
      FErr <= '0';
      OErr <= '0';
      DRdy <= '0';
      compteur_ready := 0;
    ELSIF rising_edge(clk) THEN

      CASE etat IS
          -- Etat d'initialisation
        WHEN init =>
          FErr <= '0';
          OErr <= '0';
          compteur_ready := 0;

          

          IF tmpClk = '1' THEN
            saveData <= (OTHERS => 'U');
				    DRdy <= '0';
            etat <= assemblage;
            compteur := 0;
          END IF;

          -- Assemblage des 8 bits de données
        WHEN assemblage =>
          IF tmpClk = '1' THEN

            IF compteur = 7 THEN
              saveData(7-compteur) <= tmpRxd;
              report "Je change le bit " & integer'image(compteur) & " de saveData en " & std_logic'image(tmpRxd);              
              compteur := 0;
              etat <= fin;
            ELSE
              -- Sauvegarde des données
              saveData(7-compteur) <= tmpRxd;
              report "Je change le bit " & integer'image(compteur) & " de saveData en " & std_logic'image(tmpRxd);
              compteur := compteur + 1;
              
            END IF;

          END IF;
          -- Fin de la réception des 8 bits de données
        WHEN fin =>

          IF tmpClk = '1' THEN
            report "Je récupère le bit de fin qui est " & std_logic'image(tmpRxd);
            -- Détection de l'erreur d'envoi
            IF tmpRxd = '0' THEN
              FErr <= '1';
              DRdy <= '0';
              etat <= init;
            ELSE
              DRdy <= '1';
              data <= saveData;
              -- Détection de l'erreur de donnée

              etat <= finy;
            END IF;

          END IF;

          -- Réinitialisation de DRdy  
        WHEN finy =>

          if (compteur_ready = 2) then 
            compteur_ready := 0;

          IF read = '0' THEN
            OErr <= '1';
          END IF;
          DRdy <= '0';
          etat <= init;
          end if;

          compteur_ready := compteur_ready + 1;
        

      END CASE;
    END IF;
  END PROCESS;

END Behavioral;