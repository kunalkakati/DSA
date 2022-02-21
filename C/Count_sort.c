#include<stdio.h>
#include<stdlib.h>

void CountSort(int * A, int size){
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    int * countArr = (int *) calloc ((max+1), sizeof(int)); //calloc initializes each block with a default value ‘0’.
    
    for (int i = 0; i < size; i++)
    {
        countArr[A[i]] += 1;
    }
    
    int i=0,j=0;

    while (j <= max)
    {
        if (countArr[j] != 0)
        {
            A[i] = j;
            i++;
            countArr[j] -= 1;
        }
        else{
            j++;
        }
    }
    
}

int main(){
    int Arr[] = {1,2,1,2,1,2};
    int size = sizeof(Arr)/sizeof(int);

    CountSort(Arr,size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Arr[i]);
    }
    


    return 0;
}