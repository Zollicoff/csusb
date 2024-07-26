#include <iostream>
#include <string>
#include <cmath>

// Function to convert binary to decimal
int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += std::pow(2, power);
        }
        power++;
    }
    return decimal;
}

// Function to convert decimal to binary
std::string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";
    std::string binary;
    while (decimal > 0) {
        binary = (decimal % 2 == 0 ? "0" : "1") + binary;
        decimal /= 2;
    }
    return binary;
}

int main() {
    std::string binary;
    int decimal;

    // Binary to Decimal
    std::cout << "Enter a binary number: ";
    std::cin >> binary;
    std::cout << "Decimal equivalent: " << binaryToDecimal(binary) << std::endl;

    // Decimal to Binary
    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;
    std::cout << "Binary equivalent: " << decimalToBinary(decimal) << std::endl;

    return 0;
}