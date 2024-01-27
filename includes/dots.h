#ifndef DOTS_H
#define DOTS_H
#include "../deps/Eigen/Dense"

class Dots {
public:
    Dots(int num_rows, int num_cols);
    void updateDots(int** newDotStates);
    void updateSingleDot(int row, int col, double newState);
    void printStates() const;

private:    
    int num_rows;
    int num_cols;
    Eigen::MatrixXd matrix;
};

#endif // DOTS_H
