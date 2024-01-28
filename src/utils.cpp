#include <iostream>

void clearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

void setColor(double value) {
    if (value < 0.33) {
        // std::cout << "\033[31m"; // Red
    } else if (value < 0.66) {
        std::cout << "\033[33m"; // Yellow
    } else {
        std::cout << "\033[31m"; // Red
    }
}

// Function to reset the color to default
void resetColor() {
    std::cout << "\033[0m";
}
