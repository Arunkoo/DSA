#include <bits/stdc++.h>
using namespace std;

// Merge function that counts inversions
int mergeAndCount(int arr[], int s, int mid, int e)
{
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int left[len1], right[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[s + i];

    for (int i = 0; i < len2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = s, invCount = 0;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            invCount += (len1 - i); // Count inversions
        }
    }

    while (i < len1)
        arr[k++] = left[i++];

    while (j < len2)
        arr[k++] = right[j++];

    return invCount;
}

// Recursive Merge Sort function that counts inversions
int mergeSortAndCount(int arr[], int s, int e)
{
    if (s >= e)
        return 0;

    int mid = s + (e - s) / 2;
    int leftCount = mergeSortAndCount(arr, s, mid);
    int rightCount = mergeSortAndCount(arr, mid + 1, e);
    int mergeCount = mergeAndCount(arr, s, mid, e);

    return leftCount + rightCount + mergeCount;
}

int main()
{
    int arr[] = {9, 4, 7, 1, 2, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int inversionCount = mergeSortAndCount(arr, 0, n - 1);

    cout << "Total Inversions: " << inversionCount << endl;
    return 0;
}
