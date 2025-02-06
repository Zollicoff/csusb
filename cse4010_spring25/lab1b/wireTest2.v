// Accepts two inputs W and X
// Gives two outputs Y and Z
// Set Y equal to the negation of X
// Set Z equal to the negation of Y

module wireTest2 (W,X,Y,Z)

    input W;
    input X;
    output Y;
    output Z;

    assign Y = !X;
    assign Z = !Y;

endmodule