#include <iostream>
#include "matrix.h"

Matrix::Matrix(int nOR, int nOC) {
    numOfRows = nOR;
    numOfColumns = nOC;

    values = new int*[numOfRows];
    for(int i = 0; i < numOfRows; i++)
        values[i] = new int[numOfColumns];
}

Matrix::~Matrix() {
    for(int i = 0; i < numOfRows; i++)
        delete [] values[i];
    delete values;
}

void Matrix::copy(Matrix *newMatrix) {
    for(int i = 0; i < numOfRows; i++) {
        delete [] values[i];
    }
    delete values;

    numOfRows = newMatrix->numOfRows;
    numOfColumns = newMatrix->numOfColumns;
    values = new int*[numOfRows];
    for(int i = 0; i < numOfRows; i++) {
        values[i] = new int[numOfColumns];
        for(int j = 0; j < numOfColumns; j++) {
            values[i][j] = newMatrix->values[i][j];
        }
    }
}


/*
void Matrix::set() {
    for(int i = 0; i < numOfRows; i++) {
        for(int j = 0; j < numOfColumns; j++) {
            std::cin >> values[i][j];
        }
    }
}
 */

void Matrix::print() const {
    for(int i = 0; i < numOfRows; i++) {
        for(int j = 0; j < numOfColumns; j++)
            std::cout << values[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Matrix::product(Matrix *A, Matrix *B) {
    if(A->numOfColumns != B->numOfRows) {
        printError();
    } else {
        for(int i = 0; i < numOfRows; i++)
            delete values[i];
        numOfRows = A->numOfRows;
        numOfColumns = B->numOfColumns;
        values = new int*[numOfRows];
        for(int i = 0; i < numOfRows; i++)
            values[i] = new int[numOfRows];

        int tmpSum;
        for(int i = 0; i < numOfRows; i++) {
            for(int j = 0; j < numOfColumns; j++) {
                tmpSum = 0;
                for(int s = 0; s < A->numOfColumns; s++) {
                    tmpSum += A->values[i][s] * B->values[s][j];
                }
                values[i][j] = tmpSum;
            }
        }
    }
}

void Matrix::transpose() {
    auto *C_transpose = new Matrix(numOfColumns, numOfRows);
    for(int i = 0; i < numOfColumns; i++) {
        for(int j = 0; j < numOfRows; j++) {
            C_transpose->values[i][j] = values[j][i];
        }
    }
    copy(C_transpose);
    delete C_transpose;
}

void Matrix::printError() {
    std::cout << "Error!\n";
}