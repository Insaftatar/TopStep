#include <iostream>

int main()
{
    std::cout<<"1 = ";
    int a;
    std::cin>> a;
    std::cout<<"2 = ";
    int b;
    std::cin>> b;
    int sum = 0;
    while(a<=b){
        if ((a * a) % 24 == 1){
            std::cout<<a;
            sum += 1;
        }
        a += 1;
    }
    std::cout<<"Sum = " <<sum;
    return 0;
}
