#include "main.h"
#include "../includes/dots.h"
#include <iostream>

void testVisualization() {
    Dots vis(5, 5); // Assuming 5x5 for illustration
    
    vis.printStates();

    std::cout << "\n" << std::endl;

    // Create a new array with some values
    int** newDotStates = new int*[5]; 

    newDotStates = {
      {0.0, 0.1, 0.2, 0.3, 0.4},
      {1.0, 1.1, 1.2, 1.3, 1.4},
      {2.0, 2.1, 2.2, 2.3, 2.4},
      {3.0, 3.1, 3.2, 3.3, 3.4},
      {4.0, 4.1, 4.2, 4.3, 4.4}
    };

    

    // Update the dots array with newDotStates
    vis.updateDots(newDotStates);


    vis.printStates();
    // Don't forget to clean up newDotStates
    for(int i = 0; i < 5; ++i) {
        delete[] newDotStates[i];
    }
    delete[] newDotStates;
}

int SETUP_COLS = 5;
int SETUP_ROWS = 5;

void testArrayDefinitions(int size_x, int size_y) {
  double myArray[5][5] = {{0}};

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5 ; ++j) {
      std::cout << i << j << ": " << myArray[i][j] << "\t";
    }
    std::cout << std::endl;

  }
}

int main() {
    testVisualization();
    testArrayDefinitions(5,10);
    return 0;

}
