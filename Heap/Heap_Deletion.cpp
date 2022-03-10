#include<iostream>
using namespace std;

// max heap.

void PrintArray(int *arr, int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Heapify(int *arr, int size, int root){
    int largest = root; //initilize largest as a root.
    int left = 2*root + 1; // left element of the root.
    int right = 2*root + 2;// right element of the root.
    int temp;

    // if left child is larger then root.
    if(left < size && arr[largest] < arr[left]){
        largest = left;
    }
    //If right child is larger than largest so far
    if(right < size && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != root){

        temp = arr[largest];
        arr[largest] = arr[root];
        arr[root] = temp;

        Heapify(arr, size, largest);

    }

}

void Delete_root(int * arr, int& size){
    int last_element = arr[size - 1];

    // replace root with last element.
    arr[0] = last_element;
    size-=1;

    // then heapify the replaced element.
    Heapify(arr, size, 0);
}

int main(){
    int arr[100] = {45, 12, 23, 10};
    int n = 4;
    PrintArray(arr,n);
    Delete_root(arr,n);
    PrintArray(arr,n);

    return 0;
}