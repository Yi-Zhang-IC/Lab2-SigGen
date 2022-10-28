module top #(
  parameter A_WIDTH = 8,
  parameter D_WIDTH = 8
)(
  // interface signals
  input  wire             clk,      // clock 
  input  wire             rst,      // reset 
  input  wire             en,       // enable
  input  wire [D_WIDTH-1:0] incr,   // increment for addr counter
  input  wire [D_WIDTH-1:0] offset, // offset
  output wire [D_WIDTH-1:0] dout1,    // output data
  output wire [D_WIDTH-1:0] dout2    // output data
);

  wire  [A_WIDTH-1:0]       address;  // interconnect wire1
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