library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity RxUnit_4 is
  port (
    clk, reset       : in  std_logic; -- Horloge et reset
    enable           : in  std_logic; -- Rythme de réception
    read             : in  std_logic; -- Lecture des données par le processeur
    rxd              : in  std_logic; -- Entrée série (bit à bit)
    data             : out std_logic_vector(7 downto 0); -- Données reçues
    Ferr, OErr, DRdy : out std_logic  -- Signaux d'état
  );
end RxUnit_4;

architecture RxUnit_arch of RxUnit_4 is
  
  signal bit_counter   : integer range 0 to 10 := 0; -- Compteur pour les bits de la trame
  signal sample_counter: integer range 0 to 15 := 0; -- Compteur pour la génération de tmpClk
  signal tmpClk        : std_logic := '0';          -- Horloge interne
  signal data_reg      : std_logic_vector(7 downto 0) := (others => '0'); -- Registre pour les données
  signal parity_bit    : std_logic := '0';          -- Bit de parité reçu
  signal stop_bit      : std_logic := '0';          -- Bit de stop reçu
  signal start_bit     : std_logic := '0';          -- Bit de start détecté
  signal receiving     : std_logic := '0';          -- Indique si une trame est en cours de réception
  signal Ferr_reg      : std_logic := '0';          -- Registre pour Ferr
  signal OErr_reg      : std_logic := '0';          -- Registre pour OErr
  signal DRdy_reg      : std_logic := '0';          -- Registre pour DRdy

begin
  -- Assignations des sorties
  data  <= data_reg;
  Ferr  <= Ferr_reg;
  OErr  <= OErr_reg;
  DRdy  <= DRdy_reg;

  -- Processus pour la gestion de tmpClk et du comptage des bits
  process(clk, reset)
  begin
    if reset = '1' then
      sample_counter <= 0;
      tmpClk <= '0';
    elsif rising_edge(clk) then
      if enable = '1' then
        if receiving = '1' then
          if sample_counter = 15 then
            sample_counter <= 0;
            tmpClk <= not tmpClk;
          else
            sample_counter <= sample_counter + 1;
          end if;
        else
          if rxd = '0' and start_bit = '0' then -- Détection du bit de start
            start_bit <= '1';
            sample_counter <= 0;
          end if;
        end if;
      end if;
    end if;
  end process;

  -- Processus pour la réception des données et la gestion des états
  process(tmpClk, reset)
  begin
    if reset = '1' then
      bit_counter <= 0;
      data_reg <= (others => '0');
      parity_bit <= '0';
      stop_bit <= '0';
      receiving <= '0';
      Ferr_reg <= '0';
      OErr_reg <= '0';
      DRdy_reg <= '0';
    elsif rising_edge(tmpClk) then
      if receiving = '1' then
        case bit_counter is
          when 0 => -- Réception du bit de start
            if rxd = '0' then
              bit_counter <= bit_counter + 1;
            else
              receiving <= '0';
            end if;
          when 1 to 8 => -- Réception des 8 bits de données
            data_reg(bit_counter - 1) <= rxd;
            bit_counter <= bit_counter + 1;
          when 9 => -- Réception du bit de parité
            parity_bit <= rxd;
            bit_counter <= bit_counter + 1;
          when 10 => -- Réception du bit de stop
            stop_bit <= rxd;
            receiving <= '0';
            if stop_bit = '0' or (parity_bit /= not xor reduce(data_reg)) then
              Ferr_reg <= '1';
            else
              DRdy_reg <= '1';
            end if;
          when others =>
            null;
        end case;
      else
        if start_bit = '1' then
          receiving <= '1';
          bit_counter <= 0;
          start_bit <= '0';
        end if;
      end if;
    end if;

    -- Gestion du signal DRdy et des erreurs
    if rising_edge(clk) then
      if DRdy_reg = '1' then
        if read = '1' then
          DRdy_reg <= '0';
          OErr_reg <= '0';
        else
          OErr_reg <= '1';
        end if;
      end if;
    end if;
  end process;

end RxUnit_arch;
