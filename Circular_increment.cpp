#include<iostream>
using namespace std;

void LinearPrint(int arr[], int size){
    cout<<"Linear increment.."<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void Circular_increment(int arr[], int size){
    cout<<"Circular Increment.."<<endl;
    int i = -1;
    while (i != 23)
    {
        if(i == 5 || i == 11 || i == 17){
            cout<<endl;
        }
        cout<<arr[(i+1)%size]<<" ";
        i++;
    }
    
}


int main(){
    int arr[6]={2,3,34,45,43,34};
    int size = sizeof(arr)/sizeof(int);
    
    
    

    // LinearPrint(arr,size);
    Circular_increment(arr,size);

    return 0;
}