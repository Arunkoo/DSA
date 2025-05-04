#include <iostream>
using namespace std;

// selection sort...
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        swap(arr[i], arr[min_index]);
    }
}

// print array...
int printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[7] = {22, 13, 10, 45, 21, 2, 19};
    int n = 7;

    cout << "Unsorted array" << endl;
    printArr(arr, n);
    selectionSort(arr, n);
    cout << "\n";
    cout << "Sorted array" << endl;
    printArr(arr, n);

    return 0;
}