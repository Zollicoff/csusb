/*
 * File: fullSubtractor.v
 * Description: Implements a 1-bit full subtractor using half subtractors
 * A full subtractor subtracts three bits (A, B, and borrow-in) and produces difference and borrow-out
 * A full subtractor is built from two half subtractors and an OR gate; 
 * The first half subtractor subtracts B from A and produces a difference and a borrow
 * The second half subtractor subtracts the borrow-in from the difference of the first half subtractor
 * The OR gate combines the borrows from the two half subtractors to produce the final borrow-out
 */

// Half Subtractor Module - Subtracts one bit from another and produces difference and borrow
module halfSubtractor(op1, op2, diff, borrow);

    // Inputs - two 1-bit operands
    input op1, op2;
    // Outputs - difference and borrow bits
    output diff, borrow;

    // XOR operation - difference is 1 if op1 and op2 are different
    assign diff = op1 ^ op2;

    // AND operation with NOT on op2 - borrow is 1 if op1=1 and op2=0
    assign borrow = op1 & !op2;

endmodule

// Full Subtractor Module - Subtracts three bits (A, B, borrow-in) and produces difference and borrow-out
module fullSubtractor(A, B, Bin, diff, Bout);

    // Input ports
    input A, B, Bin;  // A is minuend, B is subtrahend, Bin is borrow-in from previous subtraction
    // Output ports
    output diff, Bout; // diff is the difference bit, Bout propagates borrow to next subtraction
    
    // Internal connections - wires to connect the half subtractors
    wire c;  // Difference output from first half subtractor
    wire d;  // Borrow output from first half subtractor
    wire e;  // Difference output from second half subtractor (unused)
    wire f;  // Borrow output from second half subtractor

    // First half subtractor - subtracts B from A
    halfSubtractor u1(A, B, c, d);

    // Second half subtractor - subtracts Bin from the result of first half subtractor
    halfSubtractor u2(c, Bin, diff, f);

    // Final borrow out is OR of both half subtractor borrows
    assign Bout = f | d;  // | is the OR operator

endmodule