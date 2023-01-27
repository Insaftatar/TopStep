#include <iostream>
#include <string>

class fio {
    std::string name;
    std::string surnames;
    std::string patronymic;

    public:
    fio() {
        std::cout << "Input name: ";
        std::cin >> this->name;
        std::cout << "Input surnames: ";
        std::cin >> this->surnames;
        std::cout << "Input patronymic: ";
        std::cin >> this->patronymic;
    }
    fio(const User &other) {
        this->name = other.name;
        this->surnames = other.surnames;
        this->patronymic = other.patronymic;
    }
    fio(std::string name, std::string surnames, std::string patronymic) {
        this->name = name;
        this->surnames = surnames;
        this->patronymic = patronymic;
    }

    void print_data() {
        std::cout << this->name << "\t" << this->surnames << "\t" << this->patronymic; 
        std::cout<<"\n";
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