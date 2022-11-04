module top #(
  parameter A_WIDTH = 8,
  parameter D_WIDTH = 8
)(
  // interface signals
  input  logic             clk,      // clock 
  input  logic             rst,      // reset 
  input  logic             en,       // enable
  input  logic [D_WIDTH-1:0] incr,   // increment for addr counter
  input  logic [D_WIDTH-1:0] offset, // offset
  output logic [D_WIDTH-1:0] dout1,    // output data
  output logic [D_WIDTH-1:0] dout2    // output data
);


  wire  [A_WIDTH-1:0]       wire1;    // interconnect counter and adder/rom
  wire  [A_WIDTH-1:0]       wire2;    // interconnect adder and rom2ports


addrCounter addrCounter (
  .clk (clk),
  .rst (rst),
  .en (en),
  .incr(incr),
  .count(wire1)
);

adder adder(
  .a (wire1),
  .b (offset),
  .sum (wire2)
);

rom2ports rom2ports(
  .clk(clk),
  .addr1(wire1),
  .addr2(wire2),
  .dout1(dout1),
  .dout2(dout2)
);

endmodule