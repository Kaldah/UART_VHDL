LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY TxUnit IS
  PORT (
    clk, reset : IN STD_LOGIC;
    enable : IN STD_LOGIC; --cette entree rythme l'emission  
    ld : IN STD_LOGIC;
    txd : OUT STD_LOGIC; --initialement a 1 (haut)
    regE : OUT STD_LOGIC; --etat des registres (E pour Enable) : 1 pour vide, 0 pour plein
    bufE : OUT STD_LOGIC; --etat des buffers
    data : IN STD_LOGIC_VECTOR(7 DOWNTO 0));
END TxUnit;

ARCHITECTURE behavorial OF TxUnit IS

  SIGNAL T : STD_LOGIC; --Transimission
  SIGNAL bit_parite : STD_LOGIC;
  TYPE t_etat IS (IDLE, CHARGEMENT, PRE_EMISSION, EMISSION, EMISSION_PARITE, LAST);
  SIGNAL etat : t_etat;
BEGIN

  PROCESS (clk, reset)

    VARIABLE bufferT : STD_LOGIC_VECTOR(7 DOWNTO 0); -- registre tampon
    VARIABLE registerT : STD_LOGIC_VECTOR(7 DOWNTO 0); --registre d'emission
    VARIABLE cpt : INTEGER := 0;
    VARIABLE buff : STD_LOGIC := '1';

  BEGIN

    IF (reset = '0') THEN
      txd <= '1';
      regE <= '1';
      buff := '1';
      cpt := 0;
      bufferT := (OTHERS => '0');
      registerT := (OTHERS => '0');
      bit_parite <= '0';
      etat <= IDLE;
    ELSIF rising_edge(clk) THEN
      CASE etat IS
        WHEN IDLE =>
          IF (ld = '1') THEN
            bufferT := data; -- on charge le buffer
            buff := '0'; -- on signale que le buffer est plein
            etat <= CHARGEMENT;
          END IF;
        WHEN CHARGEMENT =>
          bit_parite <= '0'; -- 
          registerT := bufferT; -- on charge le registre d'emission avec le registre tampon
          regE <= '0'; -- on signale que le registre d'emission est plein
          buff := '1'; -- on signale que le buffer est vide
          etat <= PRE_EMISSION;

        WHEN PRE_EMISSION =>
          IF (ld = '1' AND buff = '1') THEN
            bufferT := data; -- on charge le buffer
            buff := '0'; -- on signale que le buffer est plein
          END IF;
          IF (enable = '1') THEN
            txd <= '0'; -- envoie du bit de start
            cpt := 7;
            etat <= EMISSION;
          END IF;

        WHEN EMISSION =>
          IF (enable = '1' AND cpt > 0) THEN
            txd <= registerT(cpt);  -- on envoie les données bit par bit
            bit_parite <= bit_parite XOR registerT(cpt); -- on calcule le bit de parite
            cpt := cpt - 1;
          ELSIF enable = '1' AND cpt = 0 THEN
            txd <= registerT(cpt);
            bit_parite <= bit_parite XOR registerT(cpt); 
            etat <= EMISSION_PARITE;
          END IF;

        WHEN EMISSION_PARITE =>
          IF (enable = '1') THEN
            registerT := (OTHERS => '0'); -- on vide le registre d'emission
            regE <= '1';                  -- on signale que le registre d'emission est vide
            txd <= bit_parite;            -- on envoie le bit de parite
            etat <= LAST;
          END IF;
          
        WHEN LAST =>
          IF (ld = '1' AND buff = '1') THEN
            bufferT := data;              -- on charge le buffer
            buff := '0';                  -- on signale que le buffer est plein
          END IF;
          IF (enable = '1') THEN
            txd <= '1';                   -- on envoie le bit de stop
            IF (buff = '0') THEN
              etat <= CHARGEMENT;
            ELSE
              etat <= IDLE;
            END IF;
          END IF;
      END CASE;
    END IF;
    bufE <= buff;
  END PROCESS;

END behavorial;