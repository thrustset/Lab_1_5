#pragma once

class Matrix {
public:
    int numOfRows;
    int numOfColumns;
    int **values;

    Matrix(int nOL, int nOR);
    ~Matrix();
    void copy(Matrix *newMatrix);

    //void set();
    void print() const;

    void product(Matrix *A, Matrix *B);
    void transpose();
    static void printError() ;
};