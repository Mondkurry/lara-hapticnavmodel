#ifndef VISUALIZATION_H
#define VISUALIZATION_H

class Visualization {
private:
    int num_rows;
    int num_cols;
    int** dots; // This declares the dots member as a 2D dynamic array.

public:
    Visualization(int num_rows, int num_cols);
    ~Visualization(); // Destructor to clean up the allocated memory.
    void printVariable();
};

#endif // VISUALIZATION_H
