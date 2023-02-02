#include <iostream>
#include <typeinfo>

template<typename T>
class Matrix {
    int n;
    T *matrix;
    public:
    Matrix() {
        int n;
        std::cout << "Введи размер: \n";
        std::cin >> n;
        this->n = n;
        this->matrix = new T[n];
        for (int i = 0; i < n; i++) {
            std::cin >> this->matrix[i];
        }
    }

    Matrix &operator+(int a) {
        for (int i = 0; i < this->n; i++) {
            this->matrix[i] += a;
        }

        return *this;
    }

    Matrix &operator-(int a) {
        for (int i = 0; i < this->n; i++) {
            this->matrix[i] -= a;
        }

        return *this;
    }

    Matrix &operator*(int a) {
        for (int i = 0; i < this->n; i++) {
            this->matrix[i] *= a;
        }

        return *this;
    }

    Matrix &operator/(int a) {
        for (int i = 0; i < this->n; i++) {
            this->matrix[i] /= a;
        }

        return *this;
    }

    void print() {
        for (int i = 0; i < this->n; i++) {
            std::cout << this->matrix[i] << "  ";
        }
        std::cout << "\n";
    }


    ~Matrix() {
        delete [] this->matrix;
    }
};


int main() {
    Matrix<int> matrix;

    matrix.print();

    std::cout << "matrix + 2; = ";
    matrix + 2;
    matrix.print();

    std::cout << "matrix - 2; = ";
    matrix - 2;
    matrix.print();

    std::cout << "matrix * 2; = ";
    matrix * 2;
    matrix.print();

    std::cout << "matrix / 2; = ";
    matrix / 2;
    matrix.print();

    return 0;
}