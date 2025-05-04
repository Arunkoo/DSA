#include <iostream>
using namespace std;

// Merge function
void mergeArray(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1; // length of left part..
    int len2 = e - mid;     // length of right part...

    int first[len1], second[len2];

    // Copy elements into left and right arrays
    int mainIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainIndex++];
    }

    // Merge sorted arrays
    int index1 = 0, index2 = 0;
    mainIndex = s; // Reset mainIndex to starting position

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainIndex++] = first[index1++];
        }
        else
        {
            arr[mainIndex++] = second[index2++];
        }
    }

    // Copy remaining elements
    while (index1 < len1)
    {
        arr[mainIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainIndex++] = second[index2++];
    }
}

// Merge Sort function
void mergeSort(int arr[], int s, int e)
{
    if (s >= e) // Corrected base case
        return;

    int mid = s + (e - s) / 2;

    // Left part
    mergeSort(arr, s, mid);
    // Right part
    mergeSort(arr, mid + 1, e);

    // Merge both parts
    mergeArray(arr, s, e);
}

// Function to print the array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; // Add newline for better output
}

int main()
{
    int arr[8] = {6, 3, 8, 5, 2, 7, 4, 1};
    int n = 8;

    cout << "Unsorted Array --> ";
    printArr(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array --> ";
    printArr(arr, n);

    return 0;
}
