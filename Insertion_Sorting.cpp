#include<iostream>
using namespace std;

int main(){
    int arr[] = {2,5,1,3,8,54,3,57,21};
    int size = sizeof(arr)/sizeof(int);

    for (int i = 0; i < size-1; i++)
    {
        for (int j = i + 1; j < 0; j++)
        {
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    


    return 0;
}