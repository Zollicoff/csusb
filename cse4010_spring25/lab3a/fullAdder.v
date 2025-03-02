/*
 * File: fullAdder.v
 * Description: Implements a 1-bit full adder using half adders
 * A full adder adds three bits (A, B, and carry-in) and produces sum and carry-out
 * A full adder is built from two half adders and an OR gate; 
 * The first half adder adds A and B and produces a sum and a carry
 * The second half adder adds the carry from the first half adder to the carry-in
 * The OR gate adds the carries from the two half adders to produce the final carry-out
 */

// Half Adder Module - Adds two bits and produces sum and carry
module halfAdder(op1, op2, sum, carry);

    // Inputs - two 1-bit operands
    input op1, op2;
    // Outputs - sum and carry bits
    output sum, carry;
    
    // XOR operation - sum is 1 if either op1 or op2 is 1, but not both
    assign sum = op1 ^ op2; // ^ is the xor operator
    // AND operation - carry is 1 only if both op1 and op2 are 1
    assign carry = op1 & op2; // & is the and operator
    
endmodule

// Full Adder Module - Adds three bits (A, B, carry-in) and produces sum and carry-out
module fullAdder(A, B, Cin, sum, Cout);

    // Input ports
    input A, B, Cin;  // A and B are the bits to add, carryIn is the carry from previous addition
    // Output ports
    output sum, Cout; // sum is the result bit, carryOut propagates to next addition
    
    // Internal connections - wires to connect the half adders
    wire c;  // Sum output from first half adder
    wire d;  // Carry output from first half adder
    wire e;  // Sum output from second half adder
    wire f;  // Carry output from second half adder
    
    // First half adder - adds A and B
    halfAdder u1(A, B, c, d);
    // Second half adder - adds carryIn and the sum from first half adder
    halfAdder u2(Cin, c, e, f);
    
    // Final carry out is OR of both half adder carries
    assign Cout = f | d;  // | is the OR operator
    // Final sum is the sum output from second half adder
    assign sum = e;
    
endmodule 