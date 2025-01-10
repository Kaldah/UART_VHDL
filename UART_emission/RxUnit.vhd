library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity RxUnit is
  port (
    clk, reset       : in  std_logic; -- Horloge pour la communication avec le processeur et reset global
    enable           : in  std_logic; -- Horloge pour rythmer la réception des bits
    read             : in  std_logic; -- Lecture de la donnée par le processeur
    rxd              : in  std_logic; -- Entrée série pour les données reçues bit à bit
    data             : out std_logic_vector(7 downto 0); -- Données reçues
    Ferr, OErr, DRdy : out std_logic -- Signaux d'état : erreur de réception, de lecture et donnée prête
  );
end RxUnit;

architecture RxUnit_arch of RxUnit is
  -- Déclaration des signaux internes
  signal bit_counter   : integer range 0 to 10 := 0; -- Compte les bits de la trame
  signal sample_counter: integer range 0 to 15 := 0; -- Compte les cycles pour tmpClk
  signal tmpClk        : std_logic := '0';          -- Horloge interne pour la réception
  signal data_reg      : std_logic_vector(7 downto 0) := (others => '0'); -- Registre pour les données
  signal parity_bit    : std_logic := '0';          -- Bit de parité reçu
  signal stop_bit      : std_logic := '0';          -- Bit de stop reçu
  signal start_bit     : std_logic := '0';          -- Détection du bit de start
  signal receiving     : std_logic := '0';          -- Indique si une trame est en cours de réception
  signal Ferr_reg      : std_logic := '0';          -- Registre pour Ferr
  signal OErr_reg      : std_logic := '0';          -- Registre pour OErr
  signal DRdy_reg      : std_logic := '0';          -- Registre pour DRdy
begin
  -- Assignation des sorties
  data  <= data_reg;
  Ferr  <= Ferr_reg;
  OErr  <= OErr_reg;
  DRdy  <= DRdy_reg;

  -- Processus pour la génération de tmpClk
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
        elsif rxd = '0' and start_bit = '0' then -- Détection du bit de start
          start_bit <= '1';
          sample_counter <= 0;
        end if;
      end if;
    end if;
  end process;

  -- Processus pour la réception des données et le contrôle des états
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
            -- Calcul de la parité directement dans ce bloc
            variable calculated_parity: std_logic := '0';
            for i in data_reg'range loop
              calculated_parity := calculated_parity XOR data_reg(i);
            end loop;
            if stop_bit = '0' or (parity_bit /= calculated_parity) then
              Ferr_reg <= '1';
            else
              DRdy_reg <= '1';
            end if;
          when others =>
            null;
        end case;
      elsif start_bit = '1' then
        receiving <= '1';
        bit_counter <= 0;
        start_bit <= '0';
      end if;
    end if;

    -- Gestion des signaux DRdy et OErr
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
