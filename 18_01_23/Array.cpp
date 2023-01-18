//Массив в классе
#include <iostream>

class Array{
    int *arr;
    int size;
    int cap;
 public:
 explicit Array(int cap){
    this->arr = new int[cap];
    this->cap = cap;
    size = 0;
 }

 void add_back(int val){
    if (this->size + 1 > this->cap){
        std::cout<<"No: cap = "<<this->cap<<"\n";
    }else{
    this->arr[size] = val;
    size += 1;
    }
 }

 void print() const {
    std::cout<< "[ ";
    for (int i = 0;i< this->size; ++i){
        std::cout << this->arr[i] << ", ";
    }
    std::cout<< "]\n";
 }

 void insert(int size, int a){
    if (this->size + 1 > size){
        this->arr[size] = a;
    }
    else{
        std::cout<<"No\n";
    }   
 }

 void erase(int index){
    for(int i = index + 1;i < this->size; ++i){
        this->arr[i - 1] = this->arr[i];
    }
    this->size -= 1;
 }

 Array &operator+(int val){
    add_back(val);
    return *this;
 } 
 
 Array &operator-(int val){
    for(int i = 0;i < this->size; ++i){
        if (arr[i] == val){
            erase(i);
        }       
    }

    return *this;
 }

 bool operator<(const Array & other){
    return this->size < other.size;
 }

 bool operator>(const Array & other){
    return this->size > other.size;
 }

 bool operator<=(const Array & other){
    return this->size <= other.size;
 }

 bool operator>=(const Array & other){
    return this->size >= other.size;
 }

 bool operator==(const Array & other){
    return this->size == other.size;
 }

 Array &operator-(const Array & other){
    for(int i = 0;i < this->size && i < other.size; ++i ){
        this->arr[i] -= other.arr[i];
    }
    return *this;
 }
 
 int &operator[](int i){
    return this->arr[i];
 }

 ~Array(){
    delete [] this->arr;
 }

};

int main(){
    //массивы
    Array arr(15);
    Array arr1(16);
    //добавление значение в массив
    arr.add_back(1);
    arr.add_back(2);
    arr.add_back(3);
    arr.add_back(4);

    //вывод массива и прибавление значения
    arr.print();
    arr.add_back(5);
    arr.add_back(6);
    arr.print();

    //замена значения в массиве
    arr.insert(3, 22);
    arr.print();

    //удаление значения
    arr.erase(3);
    arr.print();

    //прибавление
    arr + 6;
    arr.print();

    //удаление
    arr - 3;
    arr.print();

    //удаление
    arr - 6 - 6;
    arr.print();

    //прибавление
    arr1 + 1 + 4 + 5  + 7;

    //проверка на < > <= >= ==
    if (arr < arr1){
        std::cout<<"arr < arr1";
    }else{
        std::cout<<"arr > arr1";
    }


    arr + 4 +7 +8;
    
    arr.print();
    arr1.print();
    arr - arr1;
    arr.print();

    return 0;
}