#include<iostream>
using namespace std;


void DisplayArray(int *A, int size){
    for (int i = 0; i < size; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Insertion_Sort(int *A, int size){
    int elem,j;
    for (int i = 1; i <  size; i++)
    {
        elem = A[i];
        j = i-1;
        while (j >= 0 && A[j] > elem)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = elem;
    }
    
}

int main(){
    int arr[] = {2,5,1,3,8,54,3,57,21};
    int size = sizeof(arr)/sizeof(int);
    
    DisplayArray(arr,size);
    Insertion_Sort(arr,size);
    DisplayArray(arr,size);
    
    
    return 0;
}