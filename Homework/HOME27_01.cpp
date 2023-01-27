#include <iostream>

class Flat{
    private:
    int sum;
    int S;
    public:
    Flat(): Flat(0, 0){}
    
    Flat(const Flat &other): Flat(other.sum, other.S){}

    Flat(int sum, int S){
        this->S = S;
        this->sum = sum;
    }

    void input(){
        std::cout<<"S = ";
        std::cin >> this->S;
        std::cout<<"sum = ";
        std::cin >> this->sum;
    }

    void print(){
        std::cout<<"S = " << this->S<<"\n"<<"sum = " << this->sum<<"\n";
    }

    void srav(int S){
        if (this->S == S){
            std::cout << "Площади равны\n";
        }
        else{
            std::cout << "Площади не равны\n";
        }
    }

    void pris(int S, int sum){
        this->S = S;
        this->sum = sum;
    }
    void pris(double S, double sum){
        this->S = S;
        this->sum = sum;
    }

    void srav2(int sum){
        if (this->sum < sum){
            std::cout << "this.sum < sum\n";
        }
        else{
            std::cout << "this.sum > sum\n";
        }
    }

    ~Flat(){}
};  

class overcoat{
    private:
    int sum;
    int tip;
    public:
    overcoat(): overcoat(0, 0){}
    
    overcoat(const overcoat &other): overcoat(other.sum, other.tip){}

    overcoat(int sum, int tip){
        this->tip = tip;
        this->sum = sum;
    }

    void input(){
        std::cout<<"tip = ";
        std::cin >> this->tip;
        std::cout<<"sum = ";
        std::cin >> this->sum;
    }

    void print(){
        std::cout<<"tip = " << this->tip<<"\n"<<"sum = " << this->sum<<"\n";
    }

    void srav(int tip){
        if (this->tip == tip){
            std::cout << "Площади равны\n";
        }
        else{
            std::cout << "Площади не равны\n";
        }
    }

    void pris(int tip, int sum){
        this->tip = tip;
        this->sum = sum;
    }
    void pris(double tip, double sum){
        this->tip = tip;
        this->sum = sum;
    }

    void srav2(int sum){
        if (this->sum < sum){
            std::cout << "this.sum < sum\n";
        }
        else{
            std::cout << "this.sum > sum\n";
        }
    }

    ~overcoat(){}
};


int main()
{
    Flat test;

    test.input();
    //test.print();
    test.srav(5);
    
    test.pris(6, 6);
    test.print();
    test.pris(7.1f, 7.1f);
    test.print();

    test.srav2(10);

    overcoat test1;

    test1.input();
    //test.print();
    test1.srav(5);
    
    test1.pris(6, 6);
    test1.print();
    test1.pris(7.1f, 7.1f);
    test1.print();

    test1.srav2(10);
    return 0;
}
