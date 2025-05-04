#include <iostream>
using namespace std;
// function...

bool linearSearch(int *arr, int size, int target)
{
    // BASE CASES...
    if (size == 0)
    {
        return 0;
    }

    if (arr[0] == target)
    {
        return true;
    }

    return linearSearch(arr + 1, size - 1, target);
}

int main()
{
    int arr[5] = {2, 4, 5, 6, 8};
    int size = 5;
    int target;

    cout << "Enter a target to find" << endl;
    cin >> target;

    bool ans = linearSearch(arr, size, target);

    cout << ans;

    return 0;
}