#include <iostream>

class String {
 private:
    std::string str;
 public:
    String(std::string str) {
        this->str = str;
    }

    String(const String &string) : String(string.str){}

    String &operator=(const String &string) {
        this->str = string.str;
        return *this;
    }

    int get_length() {
        return this->str.length();
    }

    void clear() {
        this->str = "";
    }

    std::string operator+(const String &string) {
        return this->str + string.str;
    }

    String &operator+=(const String &string) {
        this->str += string.str;
        return *this;
    }

    bool operator==(const String &string) {
        if (this->str == string.str) {
            return true;
        }
        return false;
    }

    bool operator!=(const String &string) {
        if (this->str != string.str) {
            return false;
        }

        return true;
    }
    
    ~String() {}
};

int main() {

    String string1("123");

    String string2("456");

    std::cout << string1 + string2<<"\n";

    string1.clear();

    std::cout << string1 + string2<<"\n";
    
    string2.clear();

    std::cout << string1 + string2<<"ewfwef";
    return 0;
}