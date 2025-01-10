
SRC = ctrlUnit.vhd          \
      echoUnit.vhd \
      diviseurClk.vhd \
      RxUnit.vhd \
      ../TxUnit/TxUnit.vhd \
      ../clkUnit/clkUnit.vhd \
      UART.vhd \
      UART_FPGA_N4.vhd

# for synthesis:
UNIT = UART_FPGA_N4
ARCH = synthesis
UCF  = UART_FPGA_N4_DDR.ucf
