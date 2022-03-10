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

void Heapify(int *arr, int n, int r){
    int largest = r;
    int left = 2*r+1;
    int right = 2*r+2;
    
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != r){
        swap(arr[largest],arr[r]);

        Heapify(arr,n,largest);
    }
}

void HeapSort(int* arr, int n){
    // Heapify the array.
    int last_parent_element = n/2-1;
    for (int i = last_parent_element; i >= 0; i--)
    {
        Heapify(arr,n,i);
    }

    for(int j = n-1; j > 0; j--){
        swap(arr[0],arr[j]);

        Heapify(arr,j,0);
    }
    
}

int main(){
    int arr[] = {2,5,1,3,8,54,3,57,21};
    int size = sizeof(arr)/sizeof(arr[0]);

    HeapSort(arr,size);
    PrintArray(arr,size);


    return 0;
}