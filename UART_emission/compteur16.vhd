library IEEE;
use IEEE.std_logic_1164.all;

entity Compteur16 is
  port (
    reset  : in std_logic;
    RxD    : in std_logic;
    enable : in std_logic;
    tmpclk : out std_logic;
    tmprxd : out std_logic
  );
end Compteur16;

architecture Behavioral of Compteur16 is
  -- Compteur de fronts d'enable
  signal count : integer range 0 to 15 := 0;
  -- Compteur de bits envoyés
  signal counter_bits : integer range 0 to 10 := 0;
  type t_etat is (repos, count8, count16);
  signal etat         : t_etat                := repos;

begin
  process (enable, reset)
  begin
    if reset = '0' then
      count  <= 0;
      tmpclk <= '0';
      tmprxd <= '0';
      etat   <= repos;
      -- L'horloge est sur les fronts montant d'enable
    elsif rising_edge(enable) then
      case etat is
        
        -- Etat de repos, attente du bit de start
        when repos =>
          count  <= 0;
          tmpclk <= '0';
          tmprxd <= '0';
          -- Bit de start reçu
          if RxD = '0' then
            etat <= count8;
          end if;
        
        -- Attend 8 fronts d'enable
        when count8 =>
          count <= count + 1;
          -- Envoie un signal tmpclk et transmet le bit
          if count = 7 then
            tmpclk <= '1';
            tmprxd <= RxD;
            count  <= 0;
            etat   <= count16;
          end if;
        
        --  Attend 8 fronts d'enable
        when count16 =>
          count <= count + 1;
          -- Envoie un signal tmpclk et transmet le bit au 16e front
          if count = 15 then
            tmprxd <= RxD;
            tmpclk <= '1';
            count  <= 0;
            -- Le 11e bit vient d'être envoyé
            if counter_bits = 10 then
              counter_bits <= 0;
              etat         <= repos;
            -- Il reste des bits à envoyer, on passe au suivant
            else
              counter_bits <= counter_bits + 1;
            end if;
          -- tmpclk reste à 0 pendant qu'on compte
          else
            tmpclk <= '0';
          end if;
      end case;
    end if;
  end process;
end Behavioral;
