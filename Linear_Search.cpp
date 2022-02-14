#include<iostream>
using namespace std;


// Return index of founded element or -1 if element does not found.
int Search(int * arr,int s, int key){

    for (int i = 0; i < s; i++)
    {
        if(arr[i] == key){
            cout<<"Element founnd."<<endl;
            return i;
        }
    }

    cout<<"Element does not found."<<endl;
    return -1;
}

int main(){
    int arr[] = {2,3,42,53,5,6,24,64,24,90};
    int size = sizeof(arr)/sizeof(int);

    int index =  Search(arr,size,42);

    return 0;
}