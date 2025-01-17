library IEEE;
use IEEE.std_logic_1164.all;

entity ControleReception is
    Port (
        clk : in std_logic;
        reset : in std_logic;
        tmprxd : in std_logic;
        tmpclk : in std_logic;
        read : in std_logic;
        data : out std_logic_vector(7 downto 0);
        Ferr : out std_logic;
        OErr : out std_logic;
        DRdy : out std_logic
    );
end ControleReception;

architecture Behavioral of ControleReception is
    -- Compteurs de bits envoyés après le bit de start
    signal bit_count : integer range 0 to 9 := 0;
    -- Bit de parité calculé en réception
    signal bit_parite : std_logic := '0';
    -- Les différents états
    type t_etat is (repos, reception, transfert);
    signal etat : t_etat := repos;
begin
    process(clk, reset)
        variable tmpFErr : std_logic := '0';
    begin
        if reset= '0' then
            data <= (others => '0');
            bit_count <= 0;
            Ferr <= '0';
            OErr <= '0';
            DRdy <= '0';
            etat <= repos;
        elsif rising_edge(clk) then
            case etat is
                when repos =>
                    Ferr <= '0';
                    OErr <= '0';
                    DRdy <= '0';
                    bit_count <= 0;
                    -- On attend le bit de start
                    if tmpclk = '1' and tmprxd = '0' then
                        etat <= reception;
                    end if;

                -- On réceptionne l'octet (8 bits), le bit de parité et le bit de stop
                when reception =>
                    if tmpclk = '1' then
                        -- On réceptionne le bit de stop
                        if bit_count = 9 then
                            -- On vérifie si le bit de stop est valide: tmprxd = 1
                            -- En cas d'erreur FErr = 1
                            tmpFErr := tmpFErr or (not tmprxd);
                            -- Le bit de stop est invalide, retour au repos et on remonte l'erreur
                            if (tmpFErr = '1') then
                                FErr <= tmpFErr;
                                etat <= repos;
                            -- Le bit de stop est valide
                            else
                                DRdy <= '1';
                                etat <= transfert;
                            end if;
                        -- On réceptionne le bit de parité
                        elsif bit_count = 8 then
                            -- On vérifie si le bit de parité est valide
                            tmpFErr := not (bit_parite xor tmprxd);
                            bit_count <= bit_count + 1;
                        -- Réception de l'octet
                        elsif bit_count < 8 then
                            -- On les reçoit de du 7e au 0e bit
                            data(7 - bit_count) <= tmprxd;
                            bit_count <= bit_count + 1;
                            bit_parite <= bit_parite xor tmprxd;
                        end if;
                    end if;
                
                -- On transfert l'octet reçu
                when transfert =>
                    DRdy <= '0';
                    -- On vérifie si le processeur a lu l'octet
                    if read = '0'then
                        OErr <= '1';
                    end if;
                    etat <= repos;
            end case;
        end if;
    end process;
end Behavioral;
