#include "../includes/dots.h"
#include "../deps/Eigen/Dense"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

Dots::Dots(int num_rows, int num_cols)
    : num_rows(num_rows), num_cols(num_cols), matrix(num_rows, num_cols), unlocked_col(num_cols) {
    matrix.setZero();
}

void Dots::setUnlockedColumn(int col) {
    if (col >= 0 && col <= num_cols) { // Include num_cols to represent all locked state
        unlocked_col = col;
    } else {
        std::cerr << "Error: Invalid column index" << std::endl;
    }
}

int Dots::getUnlockedColumn() const {
    return unlocked_col;
}

void Dots::updateDots(int** newDotStates) {
    // Only update columns if they are unlocked
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            if (j == unlocked_col || unlocked_col == num_cols) {
                matrix(i, j) = newDotStates[i][j];
            }
        }
    }
}

void Dots::updateSingleDot(int row, int col, double newState) {
    if (row >= 0 && row < num_rows && col >= 0 && col < num_cols) {
        if (col == unlocked_col || unlocked_col == num_cols) {
            matrix(row, col) = newState;
        }
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
