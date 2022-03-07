#include<stdio.h>

//function return index of searched element or -1 if not found.
int Linear_Search(int *A, int s, int key){
    for (int i = 0; i < s; i++)
    {
        if(A[i] == key){
            printf("Element found.\n");
            return i;
        }
    }
    printf("Element does not found.\n");
    return -1;
}

int main(){
    int arr[] = {2,3,4,20,34,24,54,5,2};
    int size = sizeof(arr)/sizeof(int);

    int index = Linear_Search(arr,size,20);
    printf("%d\n", arr[index]);

    return 0;
}