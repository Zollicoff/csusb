`timescale 1ns/1ns
`include "NANDusingNOR.v"

module NANDusingNOR_tb;

    // Inputs
    reg A;
    reg B;
    
    // Output
    wire Q;
    
    // Instantiate the NANDusingNOR module
    NANDusingNOR uut (
        .A(A),
        .B(B),
        .Q(Q)
    );
    
    // Test stimulus
    initial begin
        // Dump waveform data
        $dumpfile("NANDusingNOR_tb.vcd");
        $dumpvars(0, NANDusingNOR_tb);
        
        // Test all input combinations with 20ns intervals
        A = 0; B = 0; #20;
        A = 0; B = 1; #20;
        A = 1; B = 0; #20;
        A = 1; B = 1; #20;
        
        $display("NANDusingNOR Test Complete!");
        $finish;
    end

endmodule