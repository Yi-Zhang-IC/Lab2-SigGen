module sigdelay #(
  parameter A_WIDTH = 8,
  parameter D_WIDTH = 8
)(
  // interface signals
  input  logic             clk,       // clock 
  input  logic             rst,       // reset 
  input  logic             en,        // counter enable
  input  logic             rd_en,     // read enable
  input  logic             wr_en,     // write enable
  input  logic [A_WIDTH-1:0] incr,    // increment for addr counter
  input  logic [A_WIDTH-1:0] offset,   // signal delay
  input  logic [D_WIDTH-1:0] mic_signal,     // input data
  output logic [D_WIDTH-1:0] delayed_signal    // output data
);

  wire  [A_WIDTH-1:0]       wire1; // interconnect wire1
  wire  [A_WIDTH-1:0]       wire2; // interconnect wire1


addrCounter addrCounter (
  .clk (clk),
  .rst (rst),
  .en (en),
  .incr(incr),
  .count(wire1)
);

adder adder (
  .a (wire1),
  .b (offset),
  .sum (wire2)

);

ram2ports ram2ports (
  .wr_addr (wire1),
  .rd_addr (wire2),
  .din (mic_signal),
  .dout (delayed_signal),
  .wr_en (wr_en),
  .rd_en (rd_en),
  .clk (clk)

);

endmodule
