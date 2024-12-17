library IEEE;
use IEEE.std_logic_1164.all;

entity RxUnit is
  port (
    clk, reset       : in  std_logic; --clk rythme la communication avec le processseur
    enable           : in  std_logic; --rythme l'unité de reception pour lire les bits
    read             : in  std_logic;
    rxd              : in  std_logic; --reception des bits un par un
    data             : out std_logic_vector(7 downto 0); --retransmission des bits du rxd
    Ferr, OErr, DRdy : out std_logic); 
    --DRdy=1 quand donnee recu, FErr=1 trame recu erronee: bit de parité ou et le bit de stop erronee, OErr=1 quand une donnee est prete, elle n'est pas lue a temps pour le processeur
end RxUnit;

--2 parties: 
-- un element gerant les instants de receptions 
--  -generation de l'horloge tmpClk (frequence de l'horloge d'emission et dont les fronts montant seront "au milieu" des bits recus)
--   -comptage de 8 tops d'enable
--   -detection du bit de start
--   -comptage de 16 tops autant de fois que necessaire pour lire toute la trame

-- une element gerant les etats de l'unite de reception
-- role: construire la donnee et verifier  s abonne reception en recuperant un bit a chaque front de tmpClk:
--   -bit de start
--   -8 bits de donnees
--   -bit de parite
--   -bit de stop

--Fin de reception
--CAS 1: Si le bit de stop ou le bit de parité est incorrect alors on avertir le processeur => FErr = 0
--CAS 2: Sinon, on position DRdy=1 et la donnee en sortie

architecture RxUnit_arch of RxUnit is

begin

end RxUnit_arch;
