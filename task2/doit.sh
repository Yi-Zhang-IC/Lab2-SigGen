#!/bin/sh

rm -rf obj_dir
rm -f counter.vcd

verilator -Wall --cc --trace top.sv rom2ports.sv addrCounter.sv adder.sv --exe sinegen_tb.cpp

make -j -C obj_dir/ -f Vtop.mk Vtop

ls /dev/ttyUSB* > vbuddy.cfg

./obj_dir/Vtop