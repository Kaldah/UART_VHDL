wave add -r testClkUnit
vcd dumpfile output.vcd
vcd dumpvars -m testClkUnit -l 0
run 2000ns
vcd dumpflush
exit
