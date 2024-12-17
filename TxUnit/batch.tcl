wave add -r testTxUnit
vcd dumpfile output.vcd
vcd dumpvars -m testTxUnit -l 0
run 8000ns
vcd dumpflush
exit
