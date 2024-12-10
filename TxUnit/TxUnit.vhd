library IEEE;
use IEEE.std_logic_1164.all;

entity TxUnit is
  port (
    clk, reset : in std_logic;
    enable : in std_logic; --cette entree rythme l'emission  
    ld : in std_logic;
    txd : out std_logic; --initialement a 1 (haut)
    regE : out std_logic; --etat des registres (E pour Enable) : 1 pour vide, 0 pour plein
    bufE : out std_logic; --etat des buffers
    data : in std_logic_vector(7 downto 0));
end TxUnit;

architecture behavorial of TxUnit is

  signal T : std_logic; --Transimission

  type t_etat is (IDLE, CHARGEMENT, PRE_EMISSION, EMISSION, LAST);
  signal etat : t_etat;

begin

  process(clk, reset)

    variable bufferT : std_logic_vector(7 downto 0); -- buffer register
    variable registerT : std_logic_vector(7 downto 0); --registre d'emission
    variable cpt : integer := 0;
    variable buff : std_logic; 
  begin
    if (reset = '0') then
      txd <= '1';
      regE <= '1';
      buff := '1';
      cpt := 0;
      etat <= IDLE;
    elsif rising_edge(clk) then
      case etat is
        when IDLE =>
          if (ld = '1') then
            bufferT := data;
            buff := '0';

            etat <= CHARGEMENT;

          end if;
        when CHARGEMENT => 
          registerT := bufferT;
          regE <= '0';
          buff := '1';
          etat <= EMISSION;

        when PRE_EMISSION =>
          if (ld='1' and buff='1') then
            bufferT := data;
            buff := '0';
          end if;
          if (enable = '1') then
            txd <= '0';
            cpt := 7;
            etat <= EMISSION;
          end if;

        when EMISSION =>
          if (ld='1' and buff='1') then
            bufferT := data;
            buff := '0';
          end if;
          if (enable = '1' and cpt > 0) then
            txd <= registerT(cpt);
            cpt := cpt - 1;
          elsif enable = '1' and cpt = 0 then
            txd <= registerT(cpt); --partie a ajouter
            etat <= LAST;
          end if;

        when LAST =>
          if (ld='1' and buff='1') then
            bufferT := data;
            buff := '0';
          end if;
          if (enable = '1' and buff='0') then
            etat <= CHARGEMENT;
          elsif (enable = '1' and buff='1') then
            txd <= '1';
            etat <= IDLE;
          end if;

        end case;
    end if;
    bufE <= buff;
  end process ;

end behavorial;
