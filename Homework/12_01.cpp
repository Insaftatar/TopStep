#include <iostream>
using namespace std;
const int n=5; 

template <typename T> 
void print_any_arr(T arr[][n]) {
    for (int i=0; i<n ; i++) {
       for (int j=0;  j<n; j++) {
           cout<<arr[i][j]<<"\t"; 
           
       }   
       cout<<"\n"; 
    } 
}  

void init_arr (int arr[][n]) 
{
    for (int i=0; i<n ; i++) {
       for (int j=0;  j<n; j++) {
           arr[i][j]= rand()% 100; 
           
       }   
    }
}

void init_arr (double matrix[][n]) 
{
    for (int i=0; i<n ; i++) {
       for (int j=0;  j<n; j++) {
           matrix[i][j]= double(rand()% 1000)/10; 
       }   
    }
} 

void init_arr (char kurt[][n]) 
{
    for (int i=0; i<n ; i++) {
       for (int j=0;  j<n; j++) {
           kurt[i][j]= (rand()% 100) + 32; 
           
       }   
    }
} 

void find_max_min(int arr[][n]) 
{ 
    
    int max = arr[0][0]; 
    int min = arr[n-1][n-1]; 
    
    for (int i=0; i<n ; i++) {
        for (int j=0;  j<n; j++) { 
            if (i==j) 
            {
                if (arr[i][j]> max) max=arr[i][j];
                if (arr[i][j]< min) min=arr[i][j];
            }
       }   
    } 
    cout<<"Max = "<<max<< " Min = "<<min<<"\n"; 
} 

void find_max_min(double ar[][n]) 
{ 
    
    double max = ar[0][0]; 
    double min = ar[n-1][n-1]; 
    
    for (int i=0; i<n ; i++) {
        for (int j=0;  j<n; j++) { 
            if (i==j) 
            {
                if (ar[i][j]> max) max=ar[i][j];
                if (ar[i][j]< min) min=ar[i][j];
            }
       }  
    } 
    cout<<"Max = "<<max<< " Min = "<<min<<"\n"; 
}  

void find_max_min(char a[][n]) 
{ 
    
    char max = a[0][0]; 
    char min = a[n-1][n-1]; 
    
    for (int i=0; i<n ; i++) {
        for (int j=0;  j<n; j++) { 
            if (i==j) 
            {
                if (a[i][j]> max) max=a[i][j];
                if (a[i][j]< min) min=a[i][j];
            }
       }   
    } 
     cout<<"Max = "<<max<< " Min = "<<min<<"\n"; 
} 

template <typename Type> 
void qsortRecurs(Type *a, int n) {
    int i = 0;
    int j = n - 1;
    
    Type mid = a[n/ 2];

    do {
        while(a[i] < mid) {
            i++;
        }
        while(a[j] > mid) {
            j--;
        }
        if (i <= j) {
            Type tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if(j > 0) {
        qsortRecurs(a, j+1);
    }
    if (i < n) {
        qsortRecurs(&a[i], n-i);
    }
}

template <typename Type> 
void sort_stroki(Type a[][n]) 
{   
    for (int i=0; i<n ; i++) 
    {   
        
        Type *tmp =new Type[n]; 
        for (int j=0; j<n; j++) 
        {
         tmp[j]=a[i][j];  
        } 
        
         qsortRecurs(tmp, n);  
         
         for (int k=0; k<n; k++ )
         {  
            cout<<tmp[k]<<" \t";  
         }
         
          cout<<" \n"; 
        delete tmp; 
    }
         cout<<"\n";  
    } 

int main()
{   
    srand(time (NULL)); 
    int arrint[n][n]; 
    double arrdoub [n][n]; 
    char arrchar [n][n]; 
    
    init_arr(arrint); 
    print_any_arr(arrint);  
    cout<<"\n"; 
    
    init_arr(arrdoub); 
    print_any_arr(arrdoub); 
    cout<<"\n"; 
    
    init_arr(arrchar); 
    print_any_arr(arrchar); 
    cout<<"\n"; 
    
    find_max_min(arrint); 
    find_max_min(arrdoub); 
    find_max_min(arrchar); 
    
    cout<<"arrays int, double, char \n"; 
    sort_stroki(arrint); 
    sort_stroki(arrdoub);  
    sort_stroki(arrchar);
    
    return 0;
}