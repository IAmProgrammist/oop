#ifndef MATRIX_TPP
#define MATRIX_TPP

#include <initializer_list>
#include <stdexcept>
#include <malloc.h>
#include <iostream>

template <typename T>
class Matrix;

template <typename T>
class MatrixRow {
    Matrix<T>* matrix;
    int index;

public:
    MatrixRow(Matrix<T>* matrix, int index) : matrix(matrix), index(index) {};

    void push_back(T element);
    T& operator()(int index_column);

    friend class Matrix<T>;
};

template <typename T>
class Matrix {
    T **data = nullptr;
    int width = 0;
    int height = 0;
    int width_capacity = 0;
    int height_capacity = 0;

public:
    Matrix() {};
    Matrix(std::initializer_list<T> init, int width, int height);
    ~Matrix();

    void push_back(std::initializer_list<T> row);
    void resize_width(int new_width);
    void resize_height(int new_height);

    int get_width();
    int get_height();

    T& operator()(int index_row, int index_column);
    MatrixRow<T> operator()(int index_row);

    friend class MatrixRow<T>;
};

template <typename T>
void MatrixRow<T>::push_back(T element) {
    this->matrix->resize_width(this->matrix->width + 1);
    this->matrix->data[this->index][this->matrix->width - 1] = element;
}

template <typename T>
T& MatrixRow<T>::operator()(int index_column) {
    if (this->index < 0 || this->index >= this->matrix->height || index_column < 0 || index_column >= this->matrix->width)
        throw std::out_of_range("Out of bounds");

    auto& res = this->matrix->data[this->index][index_column];

    return res;
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<T> init, int width, int height) {
    if (init.size() != width * height)
        throw std::invalid_argument("Initializer list size conditions are not met");

    this->resize_width(width);
    this->resize_height(height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            (*this)(i, j) = *(init.begin() + (i * width + j));
        }
    }
}

template <typename T>
void Matrix<T>::push_back(std::initializer_list<T> row) {
    if (row.size() != this->width)
        throw std::invalid_argument("Initializer list size conditions are not met");

    this->resize_height(this->height + 1);
    for (int i = 0; i < this->width; i++) {
        (*this)(this->height - 1, i) = *(row.begin() + i);
    }
}

template <typename T>
void Matrix<T>::resize_width(int new_width) {
    this->width = new_width;

    if (this->width > this->width_capacity) {
        this->width_capacity = std::max(this->width * 2 + 1, this->width_capacity * 2 + 1);

        for (int i = 0; i < this->height_capacity; i++) {
            this->data[i] = (T*) realloc(this->data[i], this->width_capacity * sizeof(T));

            if (!this->data[i])
                throw std::length_error("Out of memory");
        }
    }
}

template <typename T>
void Matrix<T>::resize_height(int new_height) {
    this->height = new_height;

    if (this->height > this->height_capacity) {
        int old_height_capacity = this->height_capacity;

        this->height_capacity = std::max(this->height * 2 + 1, this->height_capacity * 2 + 1);
        this->data = (T**) realloc(this->data, this->height_capacity * sizeof(T*));

        if (!this->data)
            throw std::length_error("Out of memory");

        for (int i = old_height_capacity; i < this->height_capacity; i++) {
            this->data[i] = (T*) malloc(this->width_capacity * sizeof(T));

            if (!this->data[i])
                throw std::length_error("Out of memory");
        }
    }
}

template <typename T>
T& Matrix<T>::operator()(int index_row, int index_column) {
    if (index_row < 0 || index_row >= this->height || index_column < 0 || index_column >= this->width)
        throw std::out_of_range("Out of bounds");

    auto& res = this->data[index_row][index_column];

    return res;
}

template <typename T>
MatrixRow<T> Matrix<T>::operator()(int index_row) {
    if (index_row < 0 || index_row >= this->height)
        throw std::out_of_range("Out of bounds");

    return MatrixRow(this, index_row);
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < this->height_capacity; i++)
        free(this->data[i]);

    free(this->data);
}

template <typename T>
int Matrix<T>::get_width() {
    return this->width;
}

template <typename T>
int Matrix<T>::get_height() {
    return this->height;
}

#endif // MATRIX_TPP
