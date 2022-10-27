module top #(
  parameter A_WIDTH = 8,
  parameter D_WIDTH = 8
)(
  // interface signals
  input  wire             clk,      // clock 
  input  wire             rst,      // reset 
  input  wire             en,       // enable
  input  wire [D_WIDTH-1:0] incr,   // increment for addr counter
  output wire [D_WIDTH-1:0] dout    // output data
);

  wire  [A_WIDTH-1:0]       address;    // interconnect wire

addrCounter addrCounter (
  .clk (clk),
  .rst (rst),
  .en (en),
  .incr(incr),
  .count(address)
);

rom sineRom(
  .clk(clk),
  .addr(address),
  .dout(dout)
);

endmodule