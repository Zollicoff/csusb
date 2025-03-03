// Create module NORgate with inputs A, B and output Q.
module NORgate (A, B, Q);

    // Inputs
    input A, B;
    
    // Output
    output Q;

    // NOR operation: Q = !(A | B)
    assign Q = !(A | B);

endmodule

// Create module NANDusingNOR with inputs A, B and output Q.
// This module implements a NAND gate using four NOR gates.
module NANDusingNOR (A, B, Q);

    // Inputs
    input A, B;
    
    // Output
    output Q;

    // Wires for intermediate signals
    wire C, D, E, F;

    // Instantiate NOR gates to build a NAND gate:
    // u1: Invert A using NOR (A, A)
    NORgate u1(A, A, C);
    // u2: Invert B using NOR (B, B)
    NORgate u2(B, B, D);
    // u3: NOR the inverted signals; note that NOR of C and D gives !(C|D) = !( !A or !B) = A and B.
    NORgate u3(C, D, E);
    // u4: Invert E to get NAND; NORing E with itself gives !(E|E) = !E = !(A and B) = A NAND B.
    NORgate u4(E, E, F);

    // Assign output Q
    assign Q = F;

endmodule