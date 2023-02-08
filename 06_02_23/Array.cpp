#include <iostream>

void array(int n, int m,int a, int b){
    srand(time(0));
    int** Mas = new int *[n];
    for (int i = 0; i < n; i++)
        Mas[i] = new int [m];
    int sum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; j++){
            Mas[i][j]=rand() % (b - a + 1) + a;
        }
 
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j)
            std::cout<<Mas[i][j]<<"\t";
        std::cout<<"\n";
    }
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j)
            sum += Mas[i][j];
        std::cout<<"Sr = "<< (double)sum / n;
    }
    
    // std::cout<<"Sr 1"<<(double)sum / (n*m);
    for (int i = 0; i < n; i++)
        delete[] Mas[i];
    delete[] Mas;
}

int main()
{
    array(3, 3, 1, 5);
    return 0;
}
