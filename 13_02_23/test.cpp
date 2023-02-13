#include <iostream>
#include <vector>

template <typename T>
class Array {
 private:
    T *array;
    int size;
    int cap;

 public:
    Array() : Array(0, 0) {}

    Array(const Array &other) {}

    Array(int size, T *arr) {
        this->array = new T[size];
        this->size = size;
        this->cap = size;

        for (int i = 0; i < size; ++i) {
            this->array[i] = arr[i];
        }
    }

    void recap(int new_cap) {
        if (new_cap <= this->cap) {
            std::cout << "Capasity > new capasity\n";
        } else {
            T* tmp_arr = this->array;
            this->array = new T[new_cap];
            this->cap = new_cap;

            for (int i = 0; i < this->size; ++i) {
                this->array[i] = tmp_arr[i];
            }
            delete [] tmp_arr;
        }
    }

    void printarr(){
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }

    void add_end(const T &val) {
        if (this->cap < this->size + 1) {
            recap(size * 2);
        }
        this->array[this->size] = val;
        this->size++;
    }

    void delete_end(){
        this->size--;
    }

    void add_head(const T &val){
        if (this->cap < this->size + 1) {
            recap(size * 2);
        }
        for (int i = size;i >= 0;--i){
            array[i]=array[i-1];
        }
        array[0] = val;
        // this->array[this->size] = val;
        this->size++;
    }

    void delete_head(){
        for (int i = 0;i < size;++i){
            array[i]=array[i+1];
        }
        this->size--;
    }

    T &operator[](int i) {
        return this->array[i];
    }

    ~Array() {
        delete [] this->array;
    }

    int getSize() { return this->size; }
};

template <typename array>
void print(array &arr){
    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout<<"\n";
}

template <typename array>
void mina(array &arr){
    int min = arr[0];
    for (int i = 0; i < arr.getSize(); ++i) {
       if(min>arr[i]){
            min = arr[i];
       } 
    }
    std::cout << "min = "<<min<<"\n";
}

template <typename array>
void mixa(array &arr){
    int mix = arr[0];
    for (int i = 0; i < arr.getSize(); ++i) {
       if(mix<arr[i]){
            mix = arr[i];
       } 
    }
    std::cout << "max = "<<mix<<"\n";
}

template <typename array>
void sred(array &arr){
    double sr = 0;
    for (int i = 0; i < arr.getSize(); ++i) {
       sr += arr[i];
    }
    sr = sr / arr.getSize();
    std::cout << "sr = "<<sr<<"\n";
}

template <typename array>
void sort(array &arr){

        for (int i = 0; i < arr.getSize() - 1; i++) {
            for (int j = 0; j < arr.getSize() - i - 1; j++) {
                if (arr[j] < arr[j] + 1) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
}

template <typename array>
void med(array &arr){
    int tmp = (arr.getSize() / 2);
    std::cout <<"med = "<< arr[tmp];
}

int main()
{
    int pointer_array [5] {1,2,3,4,5};
    Array<int> pointerarray(5,pointer_array);

    print(pointerarray);
    pointerarray.add_end(4);
    print(pointerarray);
    pointerarray.delete_end();
    print(pointerarray);;
    pointerarray.add_head(3);
    print(pointerarray);
    pointerarray.delete_head();
    print(pointerarray);
    mina(pointerarray);
    mixa(pointerarray);
    sred(pointerarray);
    sort(pointerarray);
    print(pointerarray);
    med(pointerarray);
    return 0;
}
