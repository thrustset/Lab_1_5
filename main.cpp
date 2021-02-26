#include <iostream>
#include "matrix.h"

int main() {
    auto *A = new Matrix(3,3);
    auto *B = new Matrix(3,2);

    /*
    std::cout << "Input matrix A:\n";
    A->set();

    std::cout << "Input matrix B:\n";
    B->set();
     */

    for(int i = 0; i < A->numOfRows; i++) {
        for(int j = 0; j < A->numOfColumns; j++) {
            A->values[i][j] = 3 * i + j + 1;
        }
    }

    for(int i = 0; i < B->numOfRows; i++) {
        for(int j = 0; j < B->numOfColumns; j++) {
            B->values[i][j] = 2 * i + j + 10;
        }
    }

    std::cout << "Matrix A:\n";
    A->print();

    std::cout << "Matrix B:\n";
    B->print();

    auto *C = new Matrix(0, 0);
    C->product(A, B);

    std::cout << "Matrix C:\n";
    C->print();

    auto *C_tr = new Matrix(0, 0);
    C_tr->copy(C);
    C_tr->transpose();

    std::cout << "Transposed C:\n";
    C_tr->print();

    delete A;
    delete B;
    delete C;
    delete C_tr;

    return 0;
}
