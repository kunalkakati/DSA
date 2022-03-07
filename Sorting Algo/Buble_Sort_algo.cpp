#include<iostream>
using namespace std;

void PrintArray(int * arr, int s){
    for (int i = 0; i < s; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Bubble_Sort(int *arr, int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<endl;
}

int main(){
    int arr[] = {2,3,4,12,3,4,6,2,34,65,234,90};
    int size = sizeof(arr)/sizeof(int);

    PrintArray(arr,size);
    Bubble_Sort(arr, size);
    PrintArray(arr,size);

    return 0;
}