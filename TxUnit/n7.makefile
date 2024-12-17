
SRC = ../clkUnit/clkUnit.vhd             \
       ../clkUnit/diviseurClk.vhd \
      TxUnit.vhd \
      testTxUnit.vhd

# for simulation:
TEST = testTxUnit
# duration (to adjust if necessary)
TIME = 8000ns
PLOT = output
