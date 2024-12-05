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

  signal bufferT : std_logic_vector(7 downto 0); -- buffer register
  signal registerT : std_logic_vector(7 downto 0); --registre d'emission
  signal T : std_logic; --Transimission

  type t_state is (IDLE, CHARGEMENT, PRE_EMMISSION,EMISSION, LAST);

begin

  process(clk, rst)
    variable cpt : integer := 0;
  begin
    if (rst = '0') then
      txd <= '1';
      regE <= '1';
      bufE <= '1';
      cpt := 0;
      t_state <= IDLE;
    elsif rising_edge(clk) then
      case t_state is
        when IDLE =>
          if (ld = '1') then
            bufferT <= data;
            bufE <= '0';

            t_state <= CHARGEMENT;

          end if;
        when CHARGEMENT => 
          registerT <= bufferT;
          regE <= '0';
          bufE <= '1';
          t_state <= EMMISSION;

        when PRE_EMMISSION =>
          if (ld='1' and bufE='1') then
            bufferT <= data;
            bufE <= '0';
          end if;
          if (enable = '1') then
            txd <= '0';
            cpt := 7;
            t_state <= EMISSION;
          end if;

        when EMISSION =>
          if (ld='1' and bufE='1') then
            bufferT <= data;
            bufE <= '0';
          end if;
          if (enable = '1' and cpt > 0) then
            txd <= registerT(cpt);
            cpt := cpt - 1;
          elsif enable = '1' and cpt = 0 then
            txd <= registerT(cpt); --partie a ajouter
            t_state <= LAST;
          end if;

        when LAST =>
          if (ld='1' and bufE='1') then
            bufferT <= data;
            bufE <= '0';
          end if;
          if (enable = '1' and bufE='0') then
            t_state <= CHARGEMENT;
          elsif (enable = '1' and bufE='1') then
            txd <= '1';
            t_state <= IDLE;
          end if;


    end if;
  end process ;

end behavorial;
