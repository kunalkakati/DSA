#include<iostream>
using namespace std;

// max heap

void PrintArray(int *arr, int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void Heapify(int * arr, int n, int r){
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

void HeapSort(int *arr, int n){

    // Heapify the array
    int last_perent_elem = n/2-1;
    for(int i = last_perent_elem; i >= 0; i--){
        Heapify(arr,n,i);
    }


    for(int j = n-1; j > 0; j--){
        // swap last element with root
        swap(arr[0],arr[j]);

        // then heapify the root.
        Heapify(arr,j,0);
    }
}

int main(){
    int arr[] ={10,4,1,9,5,3,8,2,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    HeapSort(arr,n);
    PrintArray(arr,n);


    return 0;
}