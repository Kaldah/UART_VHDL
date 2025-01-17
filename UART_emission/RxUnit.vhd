library IEEE;
use IEEE.std_logic_1164.all;

entity RxUnit is
  port (
    clk, reset       : in  std_logic; --clk rythme la communication avec le processseur
    enable           : in  std_logic; --rythme l'unité de reception pour lire les bits
    read             : in  std_logic; -- a 1 si le processeur veut lire data
    rxd              : in  std_logic; --reception des bits un par un
    data             : out std_logic_vector(7 downto 0); --retransmission des bits du rxd
    Ferr, OErr, DRdy : out std_logic); 
    --DRdy=1 quand donnee recu, 
    --FErr=1 trame recu erronee: bit de parité ou et le bit de stop erronee 
    --OErr=1 quand une donnee est prete, elle n'est pas lue a temps pour le processeur
end RxUnit;

architecture Behavioral of RxUnit is
  signal tmpclk : std_logic;
  signal tmprxd : std_logic;

  component Compteur16
    port (
      reset : in std_logic;
      enable : in std_logic;
      RxD : in std_logic;
      tmpclk : out std_logic;
      tmprxd : out std_logic
    );
  end component;

  component ControleReception
    port (
      clk : in std_logic;
      reset : in std_logic;
      tmpclk : in std_logic;
      tmprxd : in std_logic;
      read : in std_logic;
      data : out std_logic_vector(7 downto 0);
      Ferr : out std_logic;
      OErr : out std_logic;
      DRdy : out std_logic
    );
  end component;

begin
  u_compteur16 : Compteur16
      port map (
          reset => reset,
          enable => enable,
          RxD => rxd,
          tmpclk => tmpclk,
          tmprxd => tmprxd
      );

  u_controleReception : ControleReception
      port map (
          clk => clk,
          reset => reset,
          tmpclk => tmpclk,
          tmprxd => tmprxd,
          read => read,
          data => data,
          Ferr => Ferr,
          OErr => OErr,
          DRdy => DRdy
      );
end Behavioral;