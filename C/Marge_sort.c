#include<stdio.h>
#include<stdlib.h>

void Marge(int * A, int low, int mid, int high){
    int B[100];
    int i = low;
    int k = low;
    int j = mid+1;

    while (i <= mid && j <= high)
    {
        if(A[i] > A[j]){
            B[k] = A[j];
            j++;
            k++;
        }
        else{
            B[k] = A[i];
            i++;
            k++;
        }
    }
    while (i<=mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for (int i = 0; i < high+1; i++)
    {
        A[i] = B[i];
    }
    
}



void Marge_sort(int * A, int low, int high){
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;
        Marge_sort(A,low,mid);
        Marge_sort(A,mid+1, high);
        Marge(A,low,mid,high);
    }
}

int main(){
    int Arr[] = {10,9,8,7,6,5,4,4,3,3,2,1,0};
    int size = sizeof(Arr)/sizeof(int);

    Marge_sort(Arr, 0, size-1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Arr[i]);
    }
    


    return 0;
}