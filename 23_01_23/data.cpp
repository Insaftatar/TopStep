#include <iostream>
#include <string>

class User {
    std::string name;
    int age;
    int *array_o;
    int size_arr;
    int cap; // size * 2

    public:
    User() {
        std::cout << "Input name: ";
        std::cin >> this->name;
        std::cout << "Input age: ";
        std::cin >> this->age;
        std::cout << "Input size: ";
        std::cin >> this->size_arr;
        std::cout << "Input arr: ";
        this->array_o = new int [size_arr * 2];
        for (int i = 0;this->size_arr>i;++i){
            std::cin >>array_o[i];
        }
    }
    User(const User &other) {
        this->array_o = new int [other.cap];
        this->size_arr = other.size_arr;
        this->age = other.age;
        this->name = other.name;
        this->cap = this->size_arr * 2;
        for (int i = 0;this->size_arr>i;++i){
            this->array_o[i] = other.array_o[i];
        }
    }
    User(std::string name, int age, int *arr, int size) {
        this->name = name;
        this->age = age;
        this->array_o = new int [size_arr * 2];
        this->size_arr = size;
        for (int i = 0;this->size_arr>i;++i){
            this->array_o[i] = arr[i];
        }
        cap = this->size_arr * 2; 
    }

    void print_data() {
        std::cout << this->name << "\t" << this->age << "\n"; 
        for (int i = 0;this->size_arr>i;++i){
            std::cout << this->array_o[i];
        }
        std::cout<<"\n";
    }
    void print_avg_arr() {
        int avg = 0;
        for (int i = 0;i < this->size_arr;++i){
            avg += this->array_o[i];
        }
        avg = avg / this->size_arr;
        std::cout << "Avg= "<< avg << "\n";
    }

    void add_to_arr(int val) {
        if (this->size_arr + 1 > this->cap){
            std::cout<<"No: cap = "<<this->cap<<"\n";
        }else{
        this->array_o[size_arr] = val;
        size_arr += 1;
        }
    }
    void del_to_arr(int index) {
        for(int i = index + 1;i < this->size_arr; ++i){
        this->array_o[i - 1] = this->array_o[i];
        }
        this->size_arr -= 1;
    }

    std::string getName() { return this->name; }
    int getAge() { return this->age; }

    void setName(std::string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
};


class Data{
    User *users;
    int size;

    public:
    Data() : Data(1) {}
    Data(const Data &other) {
        this->users = new User[other.size];
        this->size = other.size;
        for (int i = 0; i < this->size; ++i) {
            this->users[i].setName(other.users[i].getName());
            this->users[i].setAge(other.users[i].getAge());
        }
    }
    explicit Data(int count_users) {
        this->users = new User[count_users];
        this->size = count_users;
    }

    void print() {
        for (int i = 0; i < this->size; ++i) {
            this->users[i].print_data();
        }

    }

    ~Data() {
        delete [] this->users;
    }
};


int main(int argc, char const *argv[])
{
    //Data test(3);
    
    //test.print();
    int arr[3] {1, 2, 3};
    User test_user("Ivan", 18, arr, 3);

    test_user.print_data();

    test_user.print_avg_arr();

    test_user.add_to_arr(4);
    
    test_user.print_data();

    test_user.add_to_arr(5);

    test_user.print_data();

    test_user.del_to_arr(0);

    test_user.print_data();

    return 0;
}