#include "../deps/Eigen/Dense"
#include "../includes/dots.h"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

int main() {
    int setup_size = 5; // 5x5 Setup
    Dots dots(setup_size, setup_size); // Create a 5x5 matrix.
    dots.printStates(); // Print the initial matrix.

    for (int i = 0; i < setup_size; ++i) {
        for (int j = 0; j < setup_size; ++j) {
            // Increment from 0 to 1.
            for (double v = 0.1; v <= 1.0; v += 0.1) {
                dots.updateSingleDot(i, j, v);
                dots.printStates();
            }
            // Decrement back to 0.
            for (double v = 0.9; v >= 0; v -= 0.1) {
                dots.updateSingleDot(i, j, v);
                dots.printStates();
            }
        }
    }
    return 0;
}
