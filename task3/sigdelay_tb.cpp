#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vsigdelay.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 10000000
#define ADDRESS_WIDTH 8
#define RAM_SZ pow(2,ADDRESS_WIDTH)

int main(int argc, char **argv, char **env) {
  int cycle;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vsigdelay* top = new Vsigdelay;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("sigdelay.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L2T3:Delay");
  //vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation input 
  top->clk = 1;
  top->en = 1;
  top->rst = 0;
  top->wr_en = 1;
  top->rd_en = 1;
  top->incr = 1;
  top->offset = 0;
  
  // intialize variables for analogue output
  vbdInitMicIn(RAM_SZ);

  // run simulation for MAX_SIM_CYC clock cycles
  for (cycle=0; cycle<MAX_SIM_CYC; cycle++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*cycle+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    top->mic_signal = vbdMicValue();
    top->offset = abs(vbdValue());     // adjust delay by changing incr

    // plot RAM input/output, send sample to DAC buffer, and print cycle count
    vbdPlot(int (top->mic_signal), 0, 255);
    vbdPlot(int (top->delayed_signal), 0, 255);
    vbdCycle(cycle);

    // either simulation finished, or 'q' is pressed
    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
      exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}
