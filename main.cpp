#include "matrix.h"

int main(int argc, char* argv[]) {

    /* declare the row and column of a matrix */
    size_t row{3};
    size_t column{3};

    /* set-up for first matrix */
    Matrix<ssize_t> first {row, column};
    first.initialize_matrix();
    std::cout << "\nfirst matrix: " << std::endl;
    first.print_matrix();

    /* set-up for second matrix */
    Matrix<ssize_t> second{row,column};
    second.initialize_matrix();
    std::cout << "\nsecond matrix: " << std::endl;
    second.print_matrix();

    /* addition of two matrices */
    if (first.get_row() == second.get_row() && first.get_column() == second.get_column()) {
        Matrix<ssize_t> result{first.get_row(), first.get_column()};
        /* overloading of + operator */
        result = first + second;
        std::cout << "\naddition result: " << std::endl;
        result.print_matrix();
    } else {
        /* if first matrix and second matrix have different order */
        std::cout << "\nmatrix addition is not possible!" << std::endl;
    }

    /* subtraction of two matrices */
    if (first.get_row() == second.get_row() && first.get_column() == second.get_column()) {
        Matrix<ssize_t>result{first.get_row(),first.get_column()};
        /* overloading of - operator */
        result = first - second;
        std::cout << "\nsubtraction result: " << std::endl;
        result.print_matrix();
    } else {
        /* if first matrix and second matrix have different order */
        std::cout << "\nmatrix subtraction is not possible!" << std::endl;
    }

    /* multiplication of two matrices */
    if (first.get_column() == second.get_row()) {
        Matrix<ssize_t> result{first.get_row(),second.get_column()};
        /* overloading of * operator */
        result = first * second;
        std::cout << "\nmultiplication result: " << std::endl;
        result.print_matrix();
    } else {
        std::cout << "\nmatrix multiplication is not possible!" << std::endl;
    }

    return 0;
}