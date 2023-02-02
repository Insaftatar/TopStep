#include <iostream>
#include <algorithm>
#include <vector>

class Array {
    int *array;
    int size;
    public:
    Array(int *arr,int size) {
        this->array = arr;
        this->size = size;
    }

    void print() {
        for (int i = 0; i < this->size; i++) {
            std::cout << this->array[i] << " ";
        }
        std::cout<<"\n";
    }

    void min() {
        int sum = this->array[0];
        for (int i = 1; i < this->size; i++) {
            if (this->array[i] < sum) {
                sum = this->array[i];
            }
        }

        std::cout<<sum<<"\n";
    }

    void max() {
        int sum = this->array[0];
        for (int i = 1; i < this->size; i++) {
            if (this->array[i] > sum) {
                sum = this->array[i];
            }
        }

        std::cout<<sum<<"\n";
    }

    void sorti() {
        std::vector<int> vec(&(this->array[0]),&(this->array[this->size]));
        sort(vec.begin(), vec.end());
        for (int i = 0; i < this->size; i++) {
            this->array[i] = vec[i];
        }
    }

    void change(int index,int val) {
        this->array[index] = val;
    }
};

int main() {

    int array[] = {2, 1, 3, 4, 5};

    Array arr(array,5);
    arr.print();
    
    std::cout<<"max ";
    arr.max();
    std::cout<<"min ";
    arr.min();

    arr.sorti();
    arr.print();

    arr.change(0, 10);
    arr.print();
    return 0;
}