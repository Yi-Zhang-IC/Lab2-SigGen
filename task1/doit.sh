#!/bin/sh

rm -rf obj_dir
rm -f counter.vcd

verilator -Wall --cc --trace top.sv rom.sv addrCounter.sv --exe sinegen_tb.cpp

make -j -C obj_dir/ -f Vtop.mk Vtop

./obj_dir/Vtop