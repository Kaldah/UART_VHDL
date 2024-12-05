SRC = UART_FPGA_N4.vhd   \
      ../clkUnit/clkUnit.vhd             \
      ../clkUnit/diviseurClk.vhd    \
      ../TxUnit/TxUnit.vhd               \
      diviseurClk.vhd          \
      echoUnit.vhd             \
      UART.vhd                 \
      ctrlUnit.vhd             \
      EltEtat.vhd            \
      EltInstants.vhd             \
      RxUnit.vhd     \
      RxTester.vhd 	

# for simulation:        
TEST = RxTester
# duration (to adjust if necessary)
TIME = 11200ns
PLOT = output

# for synthesis:
UNIT = UART_FPGA_N4
ARCH = synthesis
#UCF  = Nexys4.ucf
UCF  = UART_FPGA_N4.ucf



