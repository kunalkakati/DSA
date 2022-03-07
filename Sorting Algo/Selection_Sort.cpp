#include<iostream>
using namespace std;

void PrintArray(int * arr, int s){
    for (int i = 0; i < s; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Selection_Sort(int *A, int size){
    
    int min, temp;
    for (int i = 0; i < size-1; i++)
    {

        min = i; // assume 'i' as index of smellest element.[to prevent swapping error].

        // for finding the index of smallest element from 'i' the update min.
        for (int j = i+1; j < size; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }

        // swap 'i' index element with smallest element from 'i'
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}


int main(){
    int A[] = {1,2,9,4,6,9,2,1,42,12,34,565,0};
    int size = sizeof(A)/sizeof(int);

    PrintArray(A,size);
    Selection_Sort(A,size);
    PrintArray(A,size);


    return 0;
}