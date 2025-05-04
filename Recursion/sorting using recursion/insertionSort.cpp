#include <iostream>
using namespace std;

// Insertion sort...
void insertionSort(int arr[], int n, int i)
{
    // base case ...
    if (i == n)
        return;
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;

    // recursion call ...
    insertionSort(arr, n, i + 1);
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
    int i;

    cout << "Unsorted array--> ";
    printArr(arr, n);
    insertionSort(arr, n, i = 1);
    cout << "Sorted array--> ";
    printArr(arr, n);
    return 0;
}