#include <iostream>
using namespace std;

// code..
bool isSorted(int arr[], int n)
{
    // base case...
    if (n == 0 || n == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool r = isSorted(arr + 1, n - 1);
        return r;
    }
}
int main()
{
    int arr[5] = {2, 4, 3, 8, 10};
    int size = 5;

    bool ans = isSorted(arr, size);

    cout << ans;

    return 0;
}