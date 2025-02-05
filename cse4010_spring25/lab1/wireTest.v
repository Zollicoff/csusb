module wireTest (A,B,C);

    input A;
    output B;
    output C;

    assign B = A;
    assign C = !A;

endmodule
