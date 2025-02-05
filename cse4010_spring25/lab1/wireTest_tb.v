`timescale 1ns / 1ns
`include "wireTest.v"

module wireTest_tb;

reg A;
wire B;
wire C;

wireTest uut (A, B, C);

initial begin

   $dumpfile("wireTest_tb.vcd");
   $dumpvars(0, wireTest_tb);

   A = 0;
   #20

   A = 1;
   #20

   A = 0;
   #20

   A = 1;
   #20

   $display("Wire test complete!");

end

endmodule
