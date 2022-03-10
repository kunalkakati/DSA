#include<iostream>
using namespace std;

// max heap.

void PrintArray(int *arr, int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Heapify(int * arr, int index){
    int temp;
    int parent = (index-1)/2;


    if(parent >= 0){
        if(arr[index] > arr[parent]){
            //swap index with parent 
            temp = arr[index];
            arr[index] = arr[parent];
            arr[parent] = temp;

            // then heapify the parent until parent less then 0.
            Heapify(arr, parent);
        }
    }
}
void Insert_into_heap(int * arr, int& size, int data){

    // insert the element 
    arr[size] = data;
    size = size + 1;

    // Heapify the inserted element.
    Heapify(arr,size-1);

}

int main(){
    int arr[100];
    int n = 0;

    Insert_into_heap(arr,n,10);
    Insert_into_heap(arr,n,23);
    Insert_into_heap(arr,n,45);
    Insert_into_heap(arr,n,12);

    PrintArray(arr,n);



    return 0;
}