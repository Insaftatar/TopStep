#include <iostream>
#include <string>
#include <fstream>

int main() {

    std::ifstream stream1;

    std::string text1 =  "",text2 = "";

    stream1.open("file1.txt");

    if (stream1.is_open()) {
        std::string temp;
        while (stream1.good()) {
            std::getline(stream1,temp);
            text1 += temp;
        }
    }

    stream1.close();

    std::ifstream stream2;

    stream2.open("file2.txt");

    if (stream2.is_open()) {
        std::string temp;
        while (stream2.good()) {
            std::getline(stream2,temp);
            text2 += temp;
        }
    }

    stream2.close();

    if (text1 == text2) {
        std::cout << "equal";
    } else {
        std::cout << text1 << "\n" << text2;
    }
}