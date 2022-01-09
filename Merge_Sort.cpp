#include<iostream>
using namespace std;

void PrintArray(int *arr, int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Merge(int * A, int low, int mid, int high){
    int * B = new int[high+1];
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
        k++;
        i++;
    }
    while (j<=high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }

    delete[] B;
}


void Merge_sort(int * A, int low, int high){
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;
        Merge_sort(A,low,mid);
        Merge_sort(A, mid+1, high);
        Merge(A,low,mid,high);
    }
    
}

int main(){
    int Arr[] = {10,9,8,7,6,5,4,4,3,3,2,1,0};
    int size = sizeof(Arr)/sizeof(int);
    PrintArray(Arr,size);
    Merge_sort(Arr,0,size-1);
    PrintArray(Arr,size);

    return 0;
}