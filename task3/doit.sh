#!/bin/sh

rm -rf obj_dir
rm -f *.vcd

verilator -Wall --cc --trace sigdelay.sv ram2ports.sv addrCounter.sv  --exe sigdelay_tb.cpp

make -j -C obj_dir/ -f Vsigdelay.mk Vsigdelay

ls /dev/ttyUSB* > vbuddy.cfg

./obj_dir/Vsigdelay