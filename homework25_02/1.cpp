#include <iostream>
#include <string>

class Student {
    protected:
    std::string name;
    int age;
    int rost;

    public: 

    Student() {}
};

class Aspirant : public Student {
    int work_mark;

    public:

    Aspirant() : Aspirant("none", 0, 0) {}

    Aspirant(std::string name, int age, int rost) {
        this->name = name;
        this->age = age;
        this->rost = rost;
    }

    std::string get_info() {
        std::string res = "";
        res += this->name + " " + std::to_string(this->age) + " " + std::to_string(this->rost);

        return res;
    }
};

std::ostream &operator<<(std::ostream &out, Aspirant &aspirant) {
    out << aspirant.get_info();

    return out;
}

int main() {

    Aspirant aspirant("Инмаф", 16, 175);

    std::cout << aspirant;

    return 0;
}