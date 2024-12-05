# environment variables XILINX and PLATFORM must be defined
# makefile variables SRC, UNIT, ARCH, TEST, TIME, PLOT and UCF must be defined

#
# Copyright (C) 2019 Jonathan Certes
# n7xilinxhelper
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# this program. If not, see <http://www.gnu.org/licenses/>.
#

all : simu

plot : simu
	${XILINX}/bin/${PLATFORM}/isimgui -view isim.wdb

syn : ${UNIT}.bit

postsyn : ${UNIT}_postsyn.vhd

ise.prj : ${SRC}
	${RM} $@
	${foreach file, ${SRC}, echo "vhdl work \"${file}\"" >> $@; }

# target device, can be overloaded by GNU make parameters:
FPGA = xc7a100t-csg324

#-------------------------------------------------------------------------------

verify_files :
ifndef XILINX
	echo "Global variable XILINX is not defined."
	echo "Is the environment set properly?"
	exit 1
endif
ifndef PLATFORM
	echo "Global variable PLATFORM is not defined."
	echo "Is the environment set properly?"
	exit 1
endif
ifndef SRC
	echo "The list of *.vhd files to compile is empty."
	echo "See the definition of variable SRC."
	exit 1
endif
	${foreach file, ${SRC}, \
    if [ ! -e ${file} ] ; \
    then echo "File \"${file}\" does not exist" ; \
    exit 1 ; \
    fi ; }

verify_simulation :
ifndef TEST
	echo "Name of the simulation top entity is not defined."
	echo "See the definition of variable TEST."
	exit 1
endif
ifndef TIME
	echo "The simulation time is not defined."
	echo "See the definition of variable TIME."
	exit 1
endif
ifndef PLOT
	echo "Name of the output plot file is not defined."
	echo "See the definition of variable PLOT."
	exit 1
endif
	echo "Verification of simulation entries is OK."

verify_synthesis :
ifndef UNIT
	echo "Name of the synthesis top entity is not defined."
	echo "See the definition of variable UNIT."
	exit 1
endif
ifndef ARCH
	echo "Name of the synthesis top architecture is not defined."
	echo "See the definition of variable ARCH."
	exit 1
endif
ifndef UCF
	echo "Name of the constraint *.ucf file is not defined."
	echo "See the definition of variable UCF."
	exit 1
endif
	if [ ! -e ${UCF} ] ; then echo "File \"${UCF}\" does not exist" ; \
    exit 1 ; fi
	echo "Verification of synthesis entries is OK."

#-------------------------------------------------------------------------------

simu : isim.wdb

view : isim.wdb
	${XILINX}/bin/${PLATFORM}/isimgui -view $^

isim.wdb : bin batch.tcl
	./bin -tclbatch batch.tcl

batch.tcl :
	${RM} $@
	echo "wave add -r ${TEST}"          >> $@
	echo "vcd dumpfile ${PLOT}.vcd"     >> $@
	echo "vcd dumpvars -m ${TEST} -l 0" >> $@
	echo "run ${TIME}"                  >> $@
	echo "vcd dumpflush"                >> $@
	echo "exit"                         >> $@

bin : ise.prj
	${XILINX}/bin/${PLATFORM}/fuse  \
	  -intstyle ise                 \
	  -incremental                  \
	  -o bin                        \
	  -prj $^                       \
	  -top ${TEST}
# no ${ARCH} in top name, don't know why...

#-------------------------------------------------------------------------------

ise.xst : ise.prj
	${RM} $@
	echo "run"          >> $@
	echo "-ifn $^"      >> $@
	echo "-ofn ${UNIT}" >> $@
	echo "-p ${FPGA}"   >> $@
	echo "-top ${UNIT}" >> $@

# synthesis:
${UNIT}.ngc : ise.xst
	${XILINX}/bin/${PLATFORM}/xst -ifn $^

# implementation, translate:
${UNIT}.ngd : ${UNIT}.ngc
	${XILINX}/bin/${PLATFORM}/ngdbuild \
	  -uc ${UCF}                       \
	  -p ${FPGA}                       \
	  $^ $@

# implementation, map:
${UNIT}_map.ncd ${UNIT}_map.pcf : ${UNIT}.ngd
	${XILINX}/bin/${PLATFORM}/map -w -p ${FPGA} $^ -o $@

# implementation, place and route:
${UNIT}.ncd : ${UNIT}_map.ncd ${UNIT}_map.pcf
	${XILINX}/bin/${PLATFORM}/par -w ${UNIT}_map.ncd $@ ${UNIT}_map.pcf

# generation of bitstream file:
${UNIT}.bit : ${UNIT}.ncd
	${XILINX}/bin/${PLATFORM}/bitgen -w $^

# generation of post-synthesis netlist:
${UNIT}_postsyn.vhd : ${UNIT}.ncd
	${XILINX}/bin/${PLATFORM}/netgen -w -ofmt vhdl -sim $^ $@

#-------------------------------------------------------------------------------

clean_prj :
	${RM} ise.prj


clean_batch :
	${RM} batch.tcl

clean_bin :
	${RM} -r bin fuse.log fuseRelaunch.cmd fuse.xmsgs isim

clean_plot :
	${RM} isim.log isim.wdb
ifdef PLOT
	${RM} ${PLOT}.vcd
endif

clean_simu : clean_batch clean_bin clean_plot


clean_xst :
	${RM} ise.xst

clean_synt :
	${RM} -r ise.srp netlist.lst _xmsgs xst
ifdef UNIT
	${RM} -r ${UNIT}.ngc ${UNIT}.lso ${UNIT}_xst.xrpt
endif

clean_translate :
	${RM} -r _ngo xlnx_auto_0_xdb
ifdef UNIT
	${RM} -r ${UNIT}.ngd ${UNIT}.bld ${UNIT}_ngdbuild.xrpt
endif

clean_map :
ifdef UNIT
	${RM} ${UNIT}_map.map ${UNIT}_map.mrp ${UNIT}_map.ncd ${UNIT}_map.ngm \
	  ${UNIT}_map.pcf ${UNIT}_map.xrpt ${UNIT}_summary.xml ${UNIT}_usage.xml
endif

clean_par :
	${RM} par_usage_statistics.html
ifdef UNIT
	${RM} ${UNIT}.ncd ${UNIT}.pad ${UNIT}_pad.csv ${UNIT}_pad.txt ${UNIT}.par \
	  ${UNIT}_par.xrpt ${UNIT}.ptwx ${UNIT}.unroutes ${UNIT}.xpi
endif

clean_bit :
	${RM} usage_statistics_webtalk.html webtalk.log
ifdef UNIT
	${RM} ${UNIT}.bgn ${UNIT}.bit ${UNIT}_bitgen.xwbt ${UNIT}.drc
endif

clean_postsyn :
ifdef UNIT
	${RM} ${UNIT}_postsyn.nlf ${UNIT}_postsyn.sdf ${UNIT}_postsyn.vhd
endif

clean_syn : clean_xst clean_synt clean_translate clean_map clean_par clean_bit \
            clean_postsyn


clean : clean_prj clean_simu clean_syn

