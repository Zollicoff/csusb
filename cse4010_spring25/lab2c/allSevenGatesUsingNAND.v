module allSevenGatesUsingNAND(
    input wire a,
    input wire b,
    output wire and_out,
    output wire or_out,
    output wire nand_out,
    output wire nor_out,
    output wire xor_out,
    output wire xnor_out,
    output wire not_out
);
    // Internal wires
    wire nand_ab;
    wire not_a;
    wire not_b;
    wire nand1, nand2, nand3;

    // NAND gate (directly computed)
    assign nand_ab = ~(a & b);
    assign nand_out = nand_ab;

    // AND gate using NAND: a AND b = NOT(NAND(a,b))
    // Here we use a NAND as inverter: AND = NAND(nand_ab, nand_ab)
    assign and_out = ~(nand_ab & nand_ab);

    // NOT gate using NAND: NOT a = NAND(a, a)
    assign not_out = ~(a & a);
    assign not_a = not_out; // reuse not_a for OR computation

    // Generate NOT b signal using NAND: NOT b = NAND(b, b)
    assign not_b = ~(b & b);

    // OR gate using NAND: a OR b = NAND(NOT a, NOT b)
    assign or_out = ~(not_a & not_b);

    // NOR gate using NAND: NOR = NOT(OR) = NAND(OR, OR)
    assign nor_out = ~(or_out & or_out);

    // XOR gate using NAND (4-NAND implementation):
    // nand1 = NAND(a, b)
    // nand2 = NAND(a, nand1)
    // nand3 = NAND(b, nand1)
    // XOR = NAND(nand2, nand3)
    assign nand1 = ~(a & b);
    assign nand2 = ~(a & nand1);
    assign nand3 = ~(b & nand1);
    assign xor_out = ~(nand2 & nand3);

    // XNOR gate using NAND: XNOR = NOT(XOR) = NAND(xor_out, xor_out)
    assign xnor_out = ~(xor_out & xor_out);

endmodule
