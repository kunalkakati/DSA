#include<iostream>
#include<climits>
using namespace std;

void PrintArray(int *arr, int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Maximum_Value_of_Array(int * A, int size){
    int max = INT16_MIN;
    for (int i = 0; i < size; i++)
    {
        if(A[i] > max){
            max = A[i];
        }
    }

    return max;
}

void CountSort(int * A, int size){
    int max = Maximum_Value_of_Array(A,size);
    int * countArr = new int[max];
    int i,j,x,y;
    //initilize all elements value zero(0).
    for ( i = 0; i <= max; i++)
    {
        countArr[i] = 0;
    }
    
    //increment the corresponding index in the count array.(if array A first element 3 then increment the count_arrays index 3).
    for ( j = 0; j < size; j++)
    {
        countArr[A[j]] += 1;
    }

    

    x=0;//counter for count_array.
    y=0;//counter for given array.

    // copy count_array index as given arrays value.
    while(x <= max){
        if(countArr[x] != 0){
            A[y] = x;
            y++;
            countArr[x] -= 1;
        }else{
            x++;
        }
    }


}

int main(){
    int A[] = {10,9,8,7,6,5,4,3,2,1,0};
    int size = sizeof(A) / sizeof(int);
    PrintArray(A,size);
    CountSort(A,size);
    PrintArray(A,size);


    return 0;
}