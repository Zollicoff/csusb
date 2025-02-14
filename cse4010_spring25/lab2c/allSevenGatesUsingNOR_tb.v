`timescale 1ns/1ns
`include "allSevenGatesUsingNOR.v"

module allSevenGatesUsingNOR_tb;
    // Declare inputs as reg and outputs as wire
    reg a, b;
    wire and_out, or_out, nand_out, nor_out, xor_out, xnor_out, not_out;
    
    // Instantiate the DUT
    allSevenGatesUsingNOR uut (
        .a(a),
        .b(b),
        .and_out(and_out),
        .or_out(or_out),
        .nand_out(nand_out),
        .nor_out(nor_out),
        .xor_out(xor_out),
        .xnor_out(xnor_out),
        .not_out(not_out)
    );
    
    // Test sequence
    initial begin
        // Generate VCD file for waveform viewing
        $dumpfile("allSevenGatesUsingNOR_tb.vcd");
        $dumpvars(0, allSevenGatesUsingNOR_tb);
        
        // Monitor the signals
        $monitor("time=%0t: a=%b, b=%b | and=%b, or=%b, nand=%b, nor=%b, xor=%b, xnor=%b, not=%b", 
                  $time, a, b, and_out, or_out, nand_out, nor_out, xor_out, xnor_out, not_out);
                  
        // Test all input combinations
        a = 0; b = 0; #10;
        a = 0; b = 1; #10;
        a = 1; b = 0; #10;
        a = 1; b = 1; #10;
        
        $finish;
    end
endmodule
