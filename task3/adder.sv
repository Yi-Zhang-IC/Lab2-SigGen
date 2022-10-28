module adder#(
    parameter WIDTH = 8
)(
    
    input logic [WIDTH-1:0] a,    //accept counter dout
    input logic [WIDTH-1:0] b,    //accept vbdvalue
    output logic [WIDTH-1:0] sum   //phaser shifted

);

always_comb begin

    sum = a - b;
    
end

endmodule
