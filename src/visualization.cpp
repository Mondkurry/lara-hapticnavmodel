#include "../includes/visualization.h"
#include <iostream>

Visualization::Visualization(int num_rows, int num_cols)
    : num_rows(num_rows), num_cols(num_cols) {
    // Allocate memory for the 2D array
    dots = new int*[num_rows];
    for(int i = 0; i < num_rows; ++i) {
        dots[i] = new int[num_cols](); // Initialize to zero
    }
}

Visualization::~Visualization() {
    // Clean up the memory allocated for the 2D array
    for(int i = 0; i < num_rows; ++i) {
        delete[] dots[i];
    }
    delete[] dots;
}

void Visualization::updateArray(int** newDotStates) {
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            dots[i][j] = newDotStates[i][j];
        }
    }
}

void Visualization::printVariable() {
    for(int i = 0; i < num_rows; ++i) {
        for(int j = 0; j < num_cols; ++j) {
            std::cout << dots[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
