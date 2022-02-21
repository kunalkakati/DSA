#include<stdio.h>

void Print(int * arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void Bubble_sort(int * arr,int size){
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
}

int main(){
    int arr[] = {1,5,3,34,54,2,34,5,4};
    int s = sizeof(arr)/sizeof(arr[0]);

    Print(arr,s);
    Bubble_sort(arr,s);
    Print(arr,s);



    return 0;
}