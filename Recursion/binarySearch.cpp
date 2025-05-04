#include <iostream>
using namespace std;

bool binarySearch(int *arr, int start, int end, int target)
{
    if (start > end) // Base case: when start crosses end, element is not found
        return false;

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return true;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, end, target); // Search right half
    else
        return binarySearch(arr, start, mid - 1, target); // Search left half
}

int main()
{
    int arr[5] = {2, 4, 6, 8, 10};
    int size = 5;
    int target;

    cout << "Enter the target to find in the array: ";
    cin >> target;

    bool ans = binarySearch(arr, 0, size - 1, target);

    cout << (ans ? "Found" : "Not Found");

    return 0;
}
