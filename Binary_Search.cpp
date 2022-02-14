#include<iostream>
using namespace std;

int Binary_Search(int *arr, int size, int key){
    int low = 0;
    int high = size -1;
    int mid;

    while (low <= high)
    {
        mid = (low+high)/2;
        
        if(arr[mid] == key){
            cout<<arr[mid]<<" found."<<endl;
            return key;
        }
        else if (arr[mid] > key)
        {
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        
    }
    
    cout<<key<<" not found."<<endl;
    return -1;
}

int main(){
    int arr[]= {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(int);

    int index = Binary_Search(arr,size,7);

    return 0;
}