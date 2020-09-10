
/* include guard */

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <bits/stdc++.h>

template <typename T>
class Matrix {
private:
    size_t row{3};
    size_t column{3};
    T** array;
public:
    Matrix();
    Matrix(size_t row, size_t column);
    ~Matrix();
    void print_matrix();
    void initialize_matrix();
    Matrix operator+ (const Matrix& matrix);
    Matrix operator- (const Matrix& matrix);
    Matrix operator* (const Matrix& matrix);
    Matrix& operator= (const Matrix& matrix);
    size_t get_row() const;
    size_t get_column() const;
};

template<typename T>
Matrix<T>::Matrix() {
    Matrix<T>(this->row, this->column);
}

template <typename T>
Matrix<T>::Matrix(size_t row, size_t column) {
    this->array = new T*[row];
    if (!this->array) {
        std::cout <<"Memory Error!\n" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        for (size_t i{0}; i < row; i++) {
            this->array[i] = new T[column];
            if (!this->array[i]) {
                std::cout << "Memory Error!\n";
                exit(EXIT_FAILURE);
            }
        }
        this->row = row;
        this->column = column;
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    for (size_t i{0}; i < this->row;i++) {
        delete [] this->array[i];
    }
    delete [] array;
}

template<typename T>
void Matrix<T>::print_matrix() {
    for (size_t i{0};i < this->row;i++) {
        for (size_t j{0};j < this->column; j++) {
            std::cout << std::setw(6) << this->array[i][j];
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Matrix<T>::initialize_matrix() {
    /* define a seed value for random_number_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 random_number_generator(seed);

    /* define an range for random numbers */
    ssize_t left_bound{-37}, right_bound{37};
    std::uniform_int_distribution<ssize_t> distinct_element(left_bound, right_bound);

    for (int i{0};i < row;i++) {
        for (int j{0};j < column;j++) {
            this->array[i][j] = distinct_element(random_number_generator);
        }
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& matrix) {
    auto *result = new Matrix(this->row,this->column);
    if (!result) {
        std::cout << "\nMemory Error!" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        for (int i{0};i < this->row;i++) {
            for (int j{0};j < this->column;j++) {
                result->array[i][j] = this->array[i][j] + matrix.array[i][j];
            }
        }
        return *result;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& matrix) {
    auto *result = new Matrix(this->row,this->column);
    if (!result) {
        std::cout << "\nMemory Error!" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        for (int i{0};i < this->row;i++) {
            for (int j{0};j < this->column;j++) {
                result->array[i][j] = this->array[i][j] - matrix.array[i][j];
            }
        }
        return *result;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& matrix) {
    auto* result = new Matrix(this->row,matrix.column);
    if (!result) {
        std::cout << "\nMemory Error!" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        int element_value;
        for (int i = 0;i < result->row;i++) {
            for (int j = 0;j < result->column;j++) {
                element_value = 0;
                for (int k = 0;k < this->column;k++) {
                    element_value += (this->array[i][k] * matrix.array[k][j]);
                }
                result->array[i][j] = element_value;
            }
        }
        return *result;
    }
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix& matrix) {
    if (this == &matrix) {
        return *this;
    } else {
        this->row = matrix.row;
        this->column = matrix.column;
        for (int i = 0;i < this->row;i++) {
            for (int j = 0;j < this->column;j++) {
                this->array[i][j] = matrix.array[i][j];
            }
        }
    }
    return *this;
}

template<typename T>
size_t Matrix<T>::get_row() const {
    return this->row;
}

template<typename T>
size_t Matrix<T>::get_column() const {
    return this->column;
}

#endif