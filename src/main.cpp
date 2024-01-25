#include "main.h"
#include "../includes/visualization.h"
#include <iostream>

void testVisualization() {
    int rows = 5;
    int cols = 5;

    // Create an instance of Visualization with 5 rows and 5 columns
    Visualization viz(rows, cols);

    // Call the printVariable() method to display the array
    viz.printVariable();
}

int main() {
    testVisualization();
    return 0;
}
