#include <iostream>

class Worker {
    std::string name;
    std::string surname;
    int money;
    std::string dole;
    std::string patronymic;
    int year;
    bool array = false;
    int size = 1;
    Worker *arrays;

    public:
    Worker(const Worker &worker) {
        this->arrays = new Worker[1];
        this->arrays[this->size - 1] = worker;
        this->array = true;
    }

    Worker() : Worker("Undef","Undef","Undef",1000,2000,"len") {}

    Worker(std::string name,std::string surname,std::string patronymic,int money,int year,std::string dol) {
        this->name = name;
        this->surname = surname;
        this->patronymic = patronymic;
        this->money = money;
        this->dole = dole;
    }

    void add(const Worker &worker) {
        this->size++;
        Worker *tmp = this->arrays;
        this->arrays = new Worker[this->size];

        for (int i = 0; i < this->size - 1 ; i++) {
            this->arrays[i] = tmp[i];
        }
        this->arrays[this->size - 1] = worker;
        delete [] tmp;
    }

    void moneys(int money) {
        for (int i  = 0; i < this->size; i++) {
            if ((this->arrays[i].money) > money) {
                std::cout << (this->arrays[i].name);
            }
        }
    }

    void years(int year) {
        for (int i  = 0; i < this->size; i++) {
            if ((this->arrays[i].year) > year) {
                std::cout << (this->arrays[i].name);
            }
        }
    }

    void dols(std::string dol) {
        for (int i  = 0; i < this->size; i++) {
            if (this->arrays[i].dole == dole) {
                std::cout << (this->arrays[i].name);
            }
        }
    }

    ~Worker() {
        if (this->array) {
            delete [] this->arrays;
        }
    }
};


int main() 
{
    Worker worker;
    Worker workers(worker);
    workers.years(2007);
    return 0;
}