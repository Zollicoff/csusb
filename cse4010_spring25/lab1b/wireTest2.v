/*
Instructions from Dr. Ahmed:
Accepts two inputs W and X
Gives two outputs Y and Z
Set Y equal to the negation of X
Set Z equal to the negation of Y
*/

// Define the wireTest2 module
module wireTest2 (W,X,Y,Z);

    // Declare the inputs and outputs
    input W;
    input X;
    output Y;
    output Z;

    // Assign Y to the negation of X
    assign Y = !X;
    // Assign Z to the negation of Y
    assign Z = !Y;

// End the wireTest2 module
endmodule
