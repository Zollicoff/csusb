// Initially sets W and X equal to 0;
// b. Wait 20 nanoseconds, then set W to 1.
// c. Wait 20 more nanoseconds, then set X to 1.
// d. Wait 20 more nanoseconds, then set W to 0.
// e. Wait 20 more nanoseconds, then set X to 0.

`timescale 1ns / 1ns
`include "wireTest2.v"

module wireTest2_tb;

reg W;
reg X;
wire Y;
wire Z;

wireTest2 uut (W, X, Y, Z);

initial begin

    $dumpfile("wireTest2_tb.vcd");
    $dumpvars(0, wiretest2_tb);

    W = 0;
    X = 0;
    #20

    W = 1;
    #20

    X = 1;
    #20

    W = 0;
    #20

    X = 0;
    #20

    $display("Wire test complete!")

end

endmodule
