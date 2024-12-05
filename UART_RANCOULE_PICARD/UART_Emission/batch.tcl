wave add -r RxTester
vcd dumpfile output.vcd
vcd dumpvars -m RxTester -l 0
run 11200ns
vcd dumpflush
exit
