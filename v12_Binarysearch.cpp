#include<iostream>
using namespace std;

void BinarySearch(int arr[],int size,int element){
    int low,mid,high;
    low=0;
    high = size-1;
    int found =0, count=0, position =0;

    while (low <=high)
    {
        mid =(low+high)/2;
        if(arr[mid] == element){
            found = 1;
            position = mid;
        }
        if(arr[mid] > element){
            high = mid -1;
        }else{
            low = mid +1;
        }
        count++;
    }

    if(found == 1){
        cout<<"Element founded via binary search at position: "<<position<<endl;
    }else{
        cout<<"Element not Exist"<<endl;
    }

    cout<<"Search "<<count<<" times"<<endl;
    
};

int main(){
    int arr[] = {1,2,44,66,88,222,424,556};
    int size = sizeof(arr)/sizeof(int);
    int element = 88;
    BinarySearch(arr,size,element);

    return 0;
}