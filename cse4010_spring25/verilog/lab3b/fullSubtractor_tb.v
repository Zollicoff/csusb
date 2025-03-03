/*
 * File: fullSubtractor_tb.v
 * Description: Testbench for the 1-bit full subtractor
 * Tests all possible input combinations (0-7) for A, B, Bin
 * The testbench uses a loop to iterate through all possible input combinations
 * It displays the results of each test case
 */
 
// Define timescale for simulation: 1 nanosecond time unit, 1 nanosecond precision
`timescale 1 ns / 1 ns
// Include the module to be tested
`include "fullSubtractor.v"

// Testbench module - no external ports
module fullSubtractor_tb;

// Test inputs - declared as registers since they will be driven
reg A, B, Bin;
// Test outputs - declared as wires since they will be monitored
wire diff, Bout;

// Instantiate the Unit Under Test (UUT) - connect to test signals
fullSubtractor uut(A, B, Bin, diff, Bout);

// Test sequence
initial begin
    // Generate VCD file for waveform viewing
    $dumpfile("fullSubtractor_tb.vcd");
    // Dump variables from the testbench (0 means all variables)
    $dumpvars(0, fullSubtractor_tb);
    
    // Test case 0: A=0, B=0, Bin=0
    {A, B, Bin} = 3'd0; #20;
    // Test case 1: A=0, B=0, Bin=1
    {A, B, Bin} = 3'd1; #20;
    // Test case 2: A=0, B=1, Bin=0
    {A, B, Bin} = 3'd2; #20;
    // Test case 3: A=0, B=1, Bin=1
    {A, B, Bin} = 3'd3; #20;
    // Test case 4: A=1, B=0, Bin=0
    {A, B, Bin} = 3'd4; #20;
    // Test case 5: A=1, B=0, Bin=1
    {A, B, Bin} = 3'd5; #20;
    // Test case 6: A=1, B=1, Bin=0
    {A, B, Bin} = 3'd6; #20;
    // Test case 7: A=1, B=1, Bin=1
    {A, B, Bin} = 3'd7; #20;
    // Display a message to indicate completion of test cases
    $display("Finished subtractions!");
    
end

endmodule
