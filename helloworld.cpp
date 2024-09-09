#include <iostream>
#include <thread>
#include <chrono>

void print_char(char c, int delay_ms) {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    // Spell out "Hello, World!" slowly
    std::string message = "Hello, World!";
    for (char c : message) {
        print_char(c, 500);
    }
    std::cout << std::endl;

    return 0;
}

