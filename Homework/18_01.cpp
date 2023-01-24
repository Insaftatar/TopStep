#include <iostream>

class drob {
    int a, b; //(a / b)

    public:
    drob(): drob(0,0){}
    drob(const drob &other) : drob(other.a, other.b){}
    drob(int a, int b){
        this->a = a;
        this->b = b;
    }

    void print(){
        std::cout << this->a << "/" << this->b << "\n";
    }

    void input(){
        std::cout << "Input a: ";
        std::cin >> this->a;
        std::cout << "Input b: ";
        std::cin >> this->b;
    }

    void plus(int val){
        val = val * this->b;

        this->a = this->a + val;
    }

    void minus(int val){
        plus(-val);
    }
    
    void ymnog(int val){
        val = val * this->a;

        this->a = val;
    }

    void delen(int val){
        this->a = this->a * 1;

        this->b = this->b * val;
    }

    ~drob(){}
};


int main()
{
    drob test;

    test.input();
    
    test.print();
    test.plus(4);
    test.print();

    test.minus(4);
    test.print();

    test.ymnog(4);
    test.print();

    test.delen(4);
    test.print();


    return 0;
}