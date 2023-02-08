#include <iostream>
#include <string>

class Parent{
 protected:
    std::string name;

 public:
    Parent():Parent("Parent"){}

    Parent(const Parent &other):Parent(other.name) {}

    Parent(const std::string &name){
        this->name = name;
        std::cout << "Hi my name " << name << "\n";
    }

    virtual void sayName(){
        std::cout << "My name " << name << "\n";
    }
    
    ~Parent(){
        std::cout << name << " is gone\n";
    }
};

class Child : public Parent{
 private:
    std::string last_name;

 public:
    Child(): Child ("Child"){}
    Child(const Child &other):Child(other.last_name){}
    Child(const std::string last_name){
        this->last_name = last_name;
        std::cout << "Hi my name " << last_name << "\n";
    }

    Child(const std::string last_name, const std::string name): Parent(name){
        this->last_name = last_name;
        std::cout << "Hi my name " << "name" << " " << last_name << "\n";
    }

    void sayLastName(){
        std::cout << "My lastname " << this->last_name << "!\n";
    }
    
    void sayHiByName(const std::string name){
        std::cout << "Hi " << name << "!\n";

    }

    ~Child(){
        std::cout << "Child " << this->last_name << " is gone\n";
    }
};


int main()
{
    Parent *teat = new Child("Ivan", "Ivanov");

    


    Child test_child("Ivanov");
    test_child.sayName();
    test_child.sayLastName();
    test_child.sayHiByName("Mike");


    test.sayName();

    return 0;
}
