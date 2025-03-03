// Set the timescale for the simulation
`timescale 1ns/1ns

// Include the NORusingNAND module
`include "NORusingNAND.v"

// Create the testbench module
module NORusingNAND_tb;

    // Inputs
    reg A;
    reg B;
    wire Q;

    // Instantiate the NORusingNAND module
    NORusingNAND uut(A, B, Q);

    // Initial begin block
    initial begin

        // Set the dump file and dump variables
        $dumpfile("NORusingNAND_tb.vcd");
        $dumpvars(0, NORusingNAND_tb);

        // Test the NORusingNAND module
        A = 0; B = 0; #20;
        A = 0; B = 1; #20;
        A = 1; B = 0; #20;
        A = 1; B = 1; #20;

        // Display "Complete!" when the simulation is done
        $display("Complete!");
    end

endmodule
