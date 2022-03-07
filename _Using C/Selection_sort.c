#include<stdio.h>

void PrintArr(int *A,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    
    printf("\n");
}

int main(){
    
    int Arr[] = {0,3,12,32,42,1,3,65,2,34};
    int size = sizeof(Arr)/sizeof(int);
    int min = 0;
    

    for (int i = 0; i < size-1; i++)
    {   
        min = i;
        
        for (int j = i+1; j < size; j++)
        {
            if (Arr[min] > Arr[j])
            {
                min = j;
            }
        }
        
        int temp = Arr[i];
        Arr[i] = Arr[min];
        Arr[min] = temp;
    }
    
    PrintArr(Arr,size);

    return 0;
}