#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

class Calc {
    private:
    int a, b;
public:
    Calc(): Calc(1, 1){}
    Calc(const Calc &other): Calc(other.a, other.b){}
    Calc(int a, int b){
        this->a = a;
        this->b = b;
    }

    virtual void plus(int a, int b) {
        std::cout << "Plus(a and b) = " << a + b << std::endl;
    }

    virtual void minus(int a, int b) {
        std::cout << "Minus(a and b) = " << a - b << std::endl;
    }

    ~Calc() {}
};

class SuperCalc : public Calc {
    public:
    void mult(int a, int b) { // умножение
        std::cout << "mult(a and b) = " << a * b << std::endl;
    }

    void div(int a, int b) { // деление
        std::cout << "div(a and b) = " << a / b << std::endl;
    }

    ~SuperCalc(){}
};

class SaveCalc : public Calc { // сохраняет последнюю операцуию
 private:
    std::string last_operation; // последняя выполненая операция

 public:
    SaveCalc(){};

    std::string getLastOperation() {
        return this->last_operation;
    }

    void plus(int a, int b) {
        std::string str = std::to_string(a) + " + " + std::to_string(b) + " = " + std::to_string(a + b);
        std::cout << str << std::endl;
    }
    void minus(int a, int b) {
        std::string str = std::to_string(a) + " - " + std::to_string(b) + " = " + std::to_string(a - b);
        std::cout << str << std::endl;
    }

    ~SaveCalc() {}
};

class CalcFile : public SaveCalc{
    private:
    std::string name_file;
    
    public:
    void in_file(std::string name_file){
        std::ofstream fout;

        fout.open(name_file);

        if (fout.is_open()) {
            std::cin.ignore();
            std::string str = ;
            fout << str << "\n";
        }
        else {
            std::cout << "File not open!!!!\n";
        }
        fout.close();
    }
};

int main() {
    Calc def_calc;
    SuperCalc super_calc;
    SaveCalc save_calc;

    def_calc.minus(100, 50);
    def_calc.plus(5, 7);

    super_calc.minus(10, 8);
    super_calc.minus(50, 10);
    super_calc.mult(7, 11);
    super_calc.div(512, 16);

    save_calc.minus(77, 8);
    save_calc.plus(8, 60);
    std::cout << save_calc.getLastOperation() << "\n";
}