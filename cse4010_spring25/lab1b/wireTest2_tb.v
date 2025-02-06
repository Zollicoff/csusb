/*
Instructions from Dr. Ahmed:
This file is used to test the wireTest2 module.
The testbench will set W and X to 0 and 1 in various combinations
and check that Y and Z are set correctly.
The testbench will output "Wire test complete!" when the test is done.
*/

// Include the wireTest2 module and timescale of 1ns
`timescale 1ns / 1ns
`include "wireTest2.v"

// Define the wireTest2_tb module
module wireTest2_tb;

// Declare the inputs and outputs
reg W;
reg X;
wire Y;
wire Z;

// Instantiate the wireTest2 module
wireTest2 uut (W, X, Y, Z);

// Define the initial block
initial begin

    // Dump the waveforms to wireTest2_tb.vcd
    $dumpfile("wireTest2_tb.vcd");
    $dumpvars(0, wireTest2_tb);

    // Set W and X to 0
    W = 0;
    X = 0;
    #20

    // Set W to 1
    W = 1;
    #20

    // Set X to 1
    X = 1;
    #20

    // Set W to 0
    W = 0;
    #20

    // Set X to 0
    X = 0;
    #20

    // Print "Wire test complete!" to the console
    $display("Wire test complete!");

// End the initial block
end

// End the wireTest2_tb module
endmodule
