#include <iostream>
using namespace std;

void PrintArray(int *arr, int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Partition(int *A, int low, int high)
{
    int povit = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= povit)
        {
            i++;
        }
        while (A[j] > povit)
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
    int A[] = {2, 3, 4, 12, 3, 4, 6, 2, 34, 65, 234, 90};
    int size = sizeof(A) / sizeof(int);

    PrintArray(A, size);
    QuickSort(A, 0, size - 1);
    PrintArray(A, size);

    return 0;
}