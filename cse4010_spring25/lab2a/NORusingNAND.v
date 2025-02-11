// Create module NANDgate with inputs A, B and output Q.
module NANDgate (A, B, Q);

    // Inputs
    input A, B;
    
    // Output
    output Q;

    // Assign Q = !(A & B)
    assign Q = !(A & B);

endmodule

// Create module NORusingNAND with inputs A, B and output Q.
module NORusingNAND (A, B, Q);

    // Inputs
    input A, B;
    
    // Output
    output Q;

    // Wires
    wire C, D, E, F;

    // Instantiate NANDgates
    NANDgate u1(A, A, C);
    NANDgate u2(B, B, D);
    NANDgate u3(C, D, E);
    NANDgate u4(E, E, F);

    // Assign Q = F
    assign Q = F;

endmodule
