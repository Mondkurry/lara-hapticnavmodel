#include "../includes/dots.h"
#include "../deps/Eigen/Dense"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>


Dots::Dots(int num_rows, int num_cols) 
    : num_rows(num_rows), num_cols(num_cols), matrix(num_rows, num_cols) {
    matrix.setZero();
}

void Dots::updateDots(int** newDotStates) {
    // Ensure the size of newDotStates matches matrix's dimensions
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            matrix(i, j) = newDotStates[i][j];
        }
    }
}

void Dots::updateSingleDot(int row, int col, double newState) {
    if (row >= 0 && row < num_rows && col >= 0 && col < num_cols) {
        matrix(row, col) = newState;
    } else {
        std::cerr << "Error: Index out of bounds" << std::endl;
    }
}

void Dots::printStates() const {
    std::cout << "\u001b[35mDots:\u001b[0m" << std::endl;
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            std::cout << std::fixed << std::setprecision(1) << matrix(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
