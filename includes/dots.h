#ifndef DOTS_H
#define DOTS_H

class Dots {
private:
    int num_rows;
    int num_cols;
    int** dots; // This declares the dots member as a 2D dynamic array.

public:
    Dots(int num_rows, int num_cols);
    ~Dots(); // Destructor to clean up the allocated memory.
    void updateDots(int** newDotStates); 
    void printStates();
};

#endif // DOTS_H
