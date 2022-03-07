#include<stdio.h>

void DisplayArray(int *A, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
}

void InsrtionSort(int *arr, int size){
    int elem, j;

    for (int i = 1; i < size; i++)
    {
        elem = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > elem)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = elem;
    }
}


int main(){
    int arr[] = {3,8,234,274,21,1,4,54,224,2};
    int size = sizeof(arr)/sizeof(int);

    DisplayArray(arr,size);
    InsrtionSort(arr,size);
    DisplayArray(arr,size);

    return 0;
}