#include <iostream>
using namespace std;

// Bubble Sort Function
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {                         // Passes through the array
        bool swapped = false; // Optimization to stop if already sorted
        for (int j = 0; j < n - i - 1; j++)
        { // Compare adjacent elements
            if (arr[j] > arr[j + 1])
            { // If out of order, swap
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break; // If no swaps, array is already sorted
    }
}

// Function to Print Array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main Function
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
