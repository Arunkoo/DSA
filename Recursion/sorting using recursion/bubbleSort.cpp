#include <iostream>
using namespace std;
// bubblesort..
void bubbleSort(int arr[], int n)
{
    // code here..
    if (n == 1)
        return;
    // one pass of bubble sort...
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }
    // array is alredy sorted..
    if (!swapped)
        return;
    // recursive call...
    bubbleSort(arr, n - 1);
}
// print array;
int print(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[7] = {22, 11, 45, 9, 6, 12, 19};
    int n = 7;

    cout << "unsorted array " << endl;
    print(arr, n);
    bubbleSort(arr, n);
    cout << "sorted array" << endl;
    print(arr, n);
    return 0;
}