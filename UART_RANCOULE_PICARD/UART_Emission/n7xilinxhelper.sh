#!/bin/bash

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

#-------------------------------------------------------------------------------

##
# \brief
#   Initialize the environement so that the path to xilinx software becomes
#   available and the target device is properly seleted.
#
# \details
#   Exports global variables XILINX and PLATFORM and local variable FPGA.
#
# \warning
#   This function needs to be modified in case the path to access xilinx
#   software or the target device changes.
#
function init() {

  xilinx_dir="/opt/Xilinx/14.7/ISE_DS/"
  licence_file="${xilinx_dir}/Xilinx.lic"
  user_licence_file="${HOME}/.Xilinx/Xilinx.lic"

  if [[ ! -r $user_licence_file ]] || \
     ( ! `cmp --quiet $licence_file $user_licence_file` )
  then
    \mkdir -p ~/.Xilinx
    echo "Initializing licence file, please wait ..."
    \cp ${licence_file} ${user_licence_file}
  fi

  # to make sure the command line works:
  export XILINX=${xilinx_dir}/ISE
  export PLATFORM=lin64

  # target device:
  #FPGA="xc7a100t-csg324"
  FPGA="xc7a100t-csg324-1"

}

#-------------------------------------------------------------------------------

##
# \brief
#   Uses echo command to print some help in stdout, then exits.
#
function echo_help_and_exit() {

  theText="
n7xilinxhelper: aims to ease the execution of xilinx (TM) software on ENSEEIHT
site.

This script comes with a makefile that contains the command to execute xilinx
(TM) command-line programs.

A configuration file following the makefile files syntax must be provided. Its
default name is \"${theConfFile}\" and must be located in the current directory.
In this file, the following variables must be defined:

SRC  : list of relative or absolute paths to VHDL *.vhd files

TEST : name of the top level entity dedicated to the simulation
TIME : simulation time as expected in the tclbatch file when running the isim
       binary file
PLOT : file root name for the *.vcd output file to be generated

UNIT : name of the top level entity dedicated to the synthesis
ARCH : name of the top level architecture dedicated to the synthesis
UCF  : relative or absolute path to the user constraint *.ucf file

This script can be executed with one of the following options:
-h
--help            : prints this help then exits

-c=<config>
--conf=<config>
--config=<config> : changes the path to the configuration file, where <config>
                    must be replaced by the new path
sim
simu
simulation
-s
--sim
--simu
--simulation      : executes isim to simulate according to the data provided by
                    variables TEST, TIME and PLOT in the configuration file
bit
syn
synthesis
-b
--bit
--syn
--synthesis       : executes xst, ngdbuild, map, par and bitgen to synthesize
                    and generate a bitstream file according to the data provided
                    by variables UNIT, ARCH and UCF in the configuration file
postsyn
-p
--postsyn         : executes netgen after a synthesis to generate a
                    post-synthesis netlist file according to the data provided
                    by variables UNIT, ARCH and UCF in the configuration file
view
plot
-v
--view
--plot            : executes isimgui after a simulation to open the wave viewer

clean
-C
--clean           : removes xilinx (TM) and n7xilinxhelper temporary files

If no option is provided, this script runs just like --simulation was provided.
"
  echo "${theText}"
  exit 0

}

#-------------------------------------------------------------------------------
#-------------------------------------------------------------------------------

scriptLocation=$( dirname ${BASH_SOURCE[0]} )
theMakefile="${scriptLocation}/Makefile"
theConfFile="n7.makefile"

init


#-----------------
# parsing argv[]:
#-----------------

DO=simulation
for i in "$@"
do
  case $i in
    -c=*|--conf=*|--config=*)
      theConfFile="${i#*=}"
    ;;

    sim|simu|simulation|-s|--sim|--simu|--simulation)
      DO="simulation"
    ;;

    bit|syn|synthesis|-b|--bit|--syn|--synthesis)
      DO="synthesis"
    ;;

    postsyn|-p|--postsyn)
      DO="postsyn"
    ;;

    view|plot|-v|--view|--plot)
      DO="view"
    ;;

    clean|-C|--clean)
      DO="clean"
    ;;

    -h|--help)
      echo_help_and_exit
    ;;

    *)
      echo "ERROR, unknown option: $i"
      echo "Use option --help for more informations."
      exit 1
    ;;
  esac
done


#---------------------------------
# verification of the input file:
#---------------------------------

if [ ! -e "${theConfFile}" ]
then
  echo "ERROR, unable to find configuration file: ${theConfFile}"
  exit 2
fi

make --file="${theConfFile}" --file="${theMakefile}" --quiet verify_files
if [ $? -ne 0 ]
then
  exit $?
fi


#---------------------------
# execution of the actions:
#---------------------------

case $DO in
  simulation)
    make --file="${theConfFile}" --file="${theMakefile}" FPGA="${FPGA}" \
      verify_simulation --quiet
    if [ $? -ne 0 ]
    then
      exit $?
    fi
    make --file="${theConfFile}" --file="${theMakefile}" FPGA="${FPGA}" simu
  ;;

  synthesis)
    make --file="${theConfFile}" --file="${theMakefile}" FPGA="${FPGA}" \
      verify_synthesis --quiet
    if [ $? -ne 0 ]
    then
      exit $?
    fi
    make --file="${theConfFile}" --file="${theMakefile}" FPGA="${FPGA}" syn
  ;;

  postsyn)
    make --file="${theConfFile}" --file="${theMakefile}" FPGA="${FPGA}" \
      verify_synthesis --quiet
    if [ $? -ne 0 ]
    then
      exit $?
    fi
    make --file="${theConfFile}" --file="${theMakefile}" FPGA="${FPGA}" postsyn
  ;;

  view)
    make --file="${theConfFile}" --file="${theMakefile}" FPGA="${FPGA}" \
      verify_simulation --quiet
    if [ $? -ne 0 ]
    then
      exit $?
    fi
    make --file="${theConfFile}" --file="${theMakefile}" FPGA="${FPGA}" view
  ;;

  clean)
    make --file="${theConfFile}" --file="${theMakefile}" FPGA="${FPGA}" clean
  ;;

  *)
    echo "ERROR, unknown action: $DO"
    exit 3
  ;;
esac

exit $?

