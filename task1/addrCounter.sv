module addrCounter#(
    parameter WIDTH = 8
)(
    //interface signals
    input logic clk,    //clock
    input logic rst,    //reset
    input logic en,    //counter enable
    input logic [7:0]incr,           //counter inrement
    output logic [WIDTH-1:0] count   //count output
);

always_ff @(posedge clk)
if(rst) count <={WIDTH{1'b0}};
else count <=count + (en ? incr : 0);  

endmodule