#include <iostream>
using namespace std;

class myArray
{
    int total_size;
    int used_size;
    int *ptr = NULL;

public:
    myArray()
    {
        ptr = new int[total_size];
    }
    void createArray(int tSize, int uSize)
    {
        total_size = tSize;
        used_size = uSize;
    }
    void setData()
    {
        int n;
        for (int i = 0; i < used_size; i++)
        {
            cout << "Enter the value of Element" << i << ": ";
            cin >> n;
            ptr[i] = n;
        }
    }
    void showData()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << ptr[i] << " ";
        }
    }
};

int main()
{
    myArray marks;

    marks.createArray(10, 3);
    marks.setData();
    marks.showData();

    return 0;
}