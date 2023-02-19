#include <iostream>
#include <string>

class Dvigatel {
    int power;
    int weight;
    std::string name;

    public:
    Dvigatel() {}

    Dvigatel(int weight, int power, std::string name) {
        this->weight = weight;
        this->name = name;
        this->power = power;
    }
    
    int get_weight() {
        return this->weight;
    }

    int get_power() {
        return this->power;
    }

    std::string get_name() {
        return this->name;
    }

};

class Car {
    int dvigatel;
    int price;
    std::string color;

    public:
    Car() {}

    Car(int dvigatel,int price,std::string color) {
        this->dvigatel = dvigatel;
        this->price = price;
        this->color = color;
    }

    int get_price() {
        return this->price;
    }

};

std::ostream &operator<<(std::ostream &out, Dvigatel dvigatel) {
    out << dvigatel.get_name() << "\n";
    out << dvigatel.get_weight() << "\n";
    out << dvigatel.get_power();
    return out;
}

std::ostream &operator<<(std::ostream &out,Car car) {
    return out << std::endl << car.get_price();
}


int main() {

    Dvigatel R4(1500,450,"BMW");

    Car car(12,8000000,"blue");

    std::cout << R4 << car;

    return 0;
}