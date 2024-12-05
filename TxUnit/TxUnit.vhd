LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY TxUnit IS
  PORT (
    clk, reset : IN STD_LOGIC;
    enable : IN STD_LOGIC;
    ld : IN STD_LOGIC;
    txd : OUT STD_LOGIC;
    regE : OUT STD_LOGIC;
    bufE : OUT STD_LOGIC;
    data : IN STD_LOGIC_VECTOR(7 DOWNTO 0));
END TxUnit;

ARCHITECTURE behavorial OF TxUnit IS

  TYPE t_etat IS (IDLE, BUFFERCHARGE, REGISTRECHARGE, ENVOIBIT, FINENVOI);
  SIGNAL etat : t_etat;
  SIGNAL bufferT : STD_LOGIC_VECTOR(7 DOWNTO 0);
  SIGNAL registerT : STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN

  PROCESS (clk, reset)
    VARIABLE cpt : INTEGER := 0;
    VARIABLE save_buffE : STD_LOGIC;
  BEGIN
    IF (reset = '0') THEN
      etat <= IDLE;
      regE <= '1';
      bufE <= '1';
      save_buffE := '0';
      txd <= '1';
    ELSIF (rising_edge(clk)) THEN
      CASE etat IS
        WHEN IDLE =>
          IF (ld = '1') THEN
            bufferT <= data;
            bufE <= '0';
            save_buffE := '0';
            etat <= BUFFERCHARGE;
          END IF;

        WHEN BUFFERCHARGE =>
          registerT <= bufferT;
          regE <= '0';
          bufE <= '1';
          save_buffE := '1';
          etat <= REGISTRECHARGE;

        WHEN REGISTRECHARGE =>
          IF (save_buffE = '1' AND ld = '1') THEN
            bufferT <= data;
            bufE <= '0';
            save_buffE := '0';
          END IF;

          IF (enable = '1') THEN
            txd <= '0';
            cpt := 7;
            etat <= ENVOIBIT;
          END IF;

        WHEN ENVOIBIT =>
          IF (save_buffE = '1' AND ld = '1') THEN
            bufferT <= data;
            bufE <= '0';
            save_buffE := '0';
          END IF;

          IF (enable = '1') THEN

            IF (cpt = 0) THEN
              txd <= registerT(cpt);
              
              etat <= FINENVOI;
            ELSE
              txd <= registerT(cpt);
              cpt := cpt - 1;
            END IF;
          END IF;

        WHEN FINENVOI =>
          IF (save_buffE = '1' AND ld = '1') THEN
            bufferT <= data;
            bufE <= '0';
            save_buffE := '0';
          END IF;

          IF (enable = '1' AND save_buffE = '1') THEN
            txd <= '1';
            etat <= IDLE;
            regE <= '1';

          ELSIF (enable = '1' AND save_buffE = '0') THEN
            txd <= '1';
            etat <= BUFFERCHARGE;
            regE <= '1';
          END IF;

        WHEN OTHERS =>
          etat <= IDLE;

      END CASE;
    END IF;
  END PROCESS;
END behavorial;