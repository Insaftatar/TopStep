#include <iostream>
using namespace std;
int main()
{
    int size,size1;
    cout<<"Введите size 1 массивa:";
    cin>>size;
    int arr[size];
    int a,b,c;
    for(int i=0;i<size;++i){
        cout<<"Введите число ";
        cin>>a;
        arr[i]=a;
    }
    cout<<"Введите size 2 массивa:";
    cin>>size1;
    int arr1[size1];

    for(int i=0;i<size1;++i){
        cout<<"Введите число ";
        cin>>b;
        arr1[i]=b;
    }
    
    int size2=size+size1;
    int arr3[size2];
    
    for(int i=0;i<size2;++i){
        if(i<size){
            arr3[i]=arr[i];
        }
        else if(i>=size){
                arr3[i]=arr1[i-size];
            }
    }
    
    cout<<"общий массив: \n";
    for(int i=0;i<size2;++i){
        cout<<arr3[i];
    }
    cout<<"\n\n";
    
    cout<<"чётный, нечётный:\n" ;
    cout<<"1) удал нечёт \n";
    cout<<"2) удал чёт\n";
    int w=0;
    int g;
    cin>>g;
    if(g==1){
        for(int i=0;i<size2;++i){
            w=arr3[i];
            if(arr3[i]%2==0){
                arr3[i]=w;
                cout<<"чет: "<<arr3[i];
            }
            else{
                w=0;
            }
        
        }
    }
    if(g==2){
        for(int i=0;i<size2;++i){
            w=arr3[i];
            if(arr3[i]%2==1){
                arr3[i]=w;
                cout<<"нечет: "<<arr3[i];
            }
            else{
                w=0;
            }
        
        }
    }
    
    return 0;
}