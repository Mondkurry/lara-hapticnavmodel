#include "main.h"
#include "../includes/visualization.h"
#include <iostream>

void testVisualization() {
    Visualization vis(5, 5); // Assuming 5x5 for illustration
    
    vis.printVariable();

    std::cout << "\n" << std::endl;

    // Create a new array with some values
    int** newDotStates = new int*[5];
    for(int i = 0; i < 5; ++i) {
        newDotStates[i] = new int[5];
        for (int j = 0; j < 5; ++j) {
            newDotStates[i][j] = i * j;
        }
    }

    // Update the dots array with newDotStates
    vis.updateArray(newDotStates);
    
    vis.printVariable();
    // Don't forget to clean up newDotStates
    for(int i = 0; i < 5; ++i) {
        delete[] newDotStates[i];
    }
    delete[] newDotStates;
}

int main() {
    testVisualization();
    return 0;
}

