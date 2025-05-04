#include <iostream>
using namespace std;

// Insertion sort...
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// print function...
int printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[7] = {5, 3, 8, 6, 2, 4, 1};
    int n = 7;

    cout << "Unsorted array--> ";
    printArr(arr, n);
    insertionSort(arr, n);
    cout << "Sorted array--> ";
    printArr(arr, n);
    return 0;
}