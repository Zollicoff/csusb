// allSevenGatesUsingNOR.v
// Implementing AND, OR, NAND, NOR, XOR, XNOR, and NOT using only NOR gates

module allSevenGatesUsingNOR(
    input  wire a,
    input  wire b,
    output wire and_out,
    output wire or_out,
    output wire nand_out,
    output wire nor_out,
    output wire xor_out,
    output wire xnor_out,
    output wire not_out
);

    // Internal wires
    wire not_a, not_b;
    wire nor_ab;
    wire term1, term2, xor_temp;
    
    // NOT gate: NOT a = a NOR a
    assign not_a  = ~(a | a);
    assign not_out = not_a;  // Use not_a for the output NOT gate
    
    // NOT b: used in other constructions
    assign not_b = ~(b | b);
    
    // OR gate: a OR b = NOT(a NOR b)
    // First, compute a NOR b
    assign nor_ab = ~(a | b);
    // Then, invert nor_ab (using a NOR as inverter) to get OR
    assign or_out = ~(nor_ab | nor_ab);
    
    // AND gate: a AND b = ~(~a OR ~b)
    // Since not_a = ~a and not_b = ~b, then:
    assign and_out = ~(not_a | not_b);
    
    // NAND gate: NAND = NOT(AND) = and_out NOR and_out
    assign nand_out = ~(and_out | and_out);
    
    // NOR gate: already computed as nor_ab
    assign nor_out = nor_ab;
    
    // XOR gate using only NOR gates
    // XOR = (a AND NOT b) OR (NOT a AND b)
    // Compute a AND NOT b as: ~(~a OR b)  [using NOR as inverter]
    assign term1 = ~(not_a | b);  // equals a AND ~b
    // Compute NOT a AND b as: ~(a OR ~b)
    assign term2 = ~(a | not_b);  // equals ~a AND b
    // Now, term1 OR term2 = NOT( (term1 NOR term2) )
    assign xor_temp = ~(term1 | term2);  
    assign xor_out  = ~(xor_temp | xor_temp);  // invert to get (term1 OR term2)
    
    // XNOR gate: simply the inversion of XOR
    assign xnor_out = ~(xor_out | xor_out);
    
endmodule
