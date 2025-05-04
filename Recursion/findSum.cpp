#include <iostream>
using namespace std;

// function for sum...
int Sum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    int sum = arr[0] + Sum(arr + 1, n - 1);
    return sum;
}

int main()
{
    int arr[5] = {2, 3, 4, 5, 6};

    int size = 5;

    cout << Sum(arr, size);

    return 0;
}