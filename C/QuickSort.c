#include <stdio.h>

void PrintArr(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");
}

int Partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void QuickSort(int *A, int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = Partition(A, low, high);
        QuickSort(A, low, partitionIndex - 1);
        QuickSort(A, partitionIndex + 1, high);
    }
}

int main()
{

    int A[] = {3, 54, 2, 2, 4, 6, 4, 32, 9};
    int size = sizeof(A) / sizeof(int);
    
    PrintArr(A, size);
    QuickSort(A, 0, size - 1);
    PrintArr(A, size);

    return 0;
}