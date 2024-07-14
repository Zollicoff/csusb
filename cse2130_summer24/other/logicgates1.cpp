#include <iostream>
#include <bitset>

bool NAND(bool a, bool b) {
    return !(a && b);
}

bool OR(bool a, bool b) {
    return a || b;
}

bool AND(bool a, bool b) {
    return a && b;
}

bool NOR(bool a, bool b) {
    return !(a || b);
}

bool NOT(bool a) {
    return !a;
}

bool circuit(bool A, bool B, bool C) {
    bool gate1 = NAND(A, B);
    bool gate2 = OR(B, C);
    bool gate3 = AND(gate1, NOT(gate2));
    bool gate4 = NOR(gate1, gate3);
    bool gate5 = AND(gate4, gate3);
    return gate5;
}

int main() {
    std::cout << "A B C | Output" << std::endl;
    std::cout << "---------" << std::endl;

    for (int i = 0; i < 8; ++i) {
        std::bitset<3> bits(i);
        bool A = bits[2];
        bool B = bits[1];
        bool C = bits[0];
        bool output = circuit(A, B, C);

        std::cout << A << " " << B << " " << C << " | " << output << std::endl;
    }

    return 0;
}
