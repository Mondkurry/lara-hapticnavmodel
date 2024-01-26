#include <iostream>
#include <../deps/Eigen/Dense>
#include <iomanip>
#include <chrono>
#include <thread>

int main() {
    Eigen::MatrixXd matrix(5, 5); // Create a 5x5 matrix.
    matrix.setZero(); // Initialize all elements to 0.

    // Function to print the matrix.
    auto printMatrix = [&]() {
        // Clear the screen and move cursor to top-left corner
        std::cout << "\033[2J\033[H";
        for (int i = 0; i < matrix.rows(); ++i) {
            for (int j = 0; j < matrix.cols(); ++j) {
                std::cout << std::fixed << std::setprecision(1) << matrix(i, j) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        // Wait for 500 ms
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    };

    // Print the initial matrix.
    printMatrix();

    // Iterate through each element.
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            // Increment from 0 to 1.
            for (double v = 0.1; v <= 1.0; v += 0.1) {
                matrix(i, j) = v;
                printMatrix();
            }
            // Decrement back to 0.
            for (double v = 0.9; v >= 0; v -= 0.1) {
                matrix(i, j) = v;
                printMatrix();
            }
        }
    }

    return 0;
}
