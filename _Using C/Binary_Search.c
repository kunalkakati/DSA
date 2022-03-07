#include<stdio.h>

//function return index of searched element or -1 if not found.
int Binary_Search(int *A, int s, int key){
    int low = 0;
    int high = s - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high)/2;
        if (key == A[mid])
        {
            printf("Element Found.\n");
            return mid;
        }
        else if (key > A[mid])
        {
            low = mid+1;
        }
        else{
            high = mid -1;
        }        
    }
    
    printf("Element does not found.\n");
    return -1;
}

int main(){
    // for binary search array must be sorted.
    int arr[] = {2,4,6,10,34,56,77,89,100,120};
    int size = sizeof(arr)/sizeof(int);

    int index = Binary_Search(arr,size,120);
    printf("%d\n", arr[index]);

    return 0;
}