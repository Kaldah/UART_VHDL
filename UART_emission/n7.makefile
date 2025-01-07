
SRC = clkUnit.vhd             \
      ctrlUnit.vhd \
      echoUnit.vhd \
      diviseurClk.vhd \
      RxUnit.vhd \
      TxUnit.vhd \
      UART.vhd \
      clkUnit.vhd \
      UART_FPGA_N4.vhd


# for synthesis:
UNIT = Nexys4
ARCH = synthesis
UCF  = UART_FPGA_N4_DDR.ucf
