#ifndef DOTS_H
#define DOTS_H

#include "../deps/Eigen/Dense"

class Dots {
public:
    Dots(int num_rows, int num_cols);
    void updateDots(int** newDotStates);
    void updateSingleDot(int row, int col, double newState);
    void updateRow(int row, double newState);
    void printStates() const;
    void setUnlockedColumn(int col);
    int getUnlockedColumn() const;

private:
    int num_rows;
    int num_cols;
    Eigen::MatrixXd matrix;
    int unlocked_col; // New member variable to track unlocked column
};

#endif // DOTS_H
