#include <iostream>
#include <random>
#include <string>

class Task {
    int **array;
    int N;
    int M;

    public:
    Task() {
        std::cout << "Столбы = ";
        std::cin >> this->N;
        std::cout << "Строки = ";
        std::cin >> this->M;
        this->array = new int *[this->N];

        for (int i = 0; i < this->N; i++) {
            this->array[i] = new int[this->M];
        }

        srand(time(NULL));
    
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
                this->array[i][j] = -85 + rand() % (85 + 85 + 1);
            }
        }
    }

    void print() {
        for (int i = 0; i < this->N; i++) {
            std::cout << std::to_string(i + 1) + ") ";
            for (int j = 0; j < this->M; j++) {
                std::cout << this->array[i][j] << " ";
            }
            std::cout << "\n";
        } 
        std::cout << "\n";
    }

    void sr() {
        for (int i = 0; i < this->N; i++) {
            double sum = 0;
            for (int j = 0; j < this->M; j++) {
                sum += this->array[i][j];
            }

            std::cout << i + 1 << ")" << sum / this->M << "\n";
        }
    }

    ~Task() {
        for (int i = 0; i < N; i++){
            delete [] this->array[i];
        }

        delete [] this->array;
    }
};

int main() {
    Task task;
    
    task.print();
    task.sr();
    return 0;
}