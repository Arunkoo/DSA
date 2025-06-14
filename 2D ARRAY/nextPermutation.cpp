#include <iostream>
using namespace std;

// function to see the permutation...
int nextPermutation(int number[], int n)
{
    int lastIndex = n - 1;
    // code here ....
    for (int i = 0; i < lastIndex; i++)
    {
        for (int j = i + 1; j < lastIndex; j++)
        {
            swap(number[j], number[j + 1]);
        }
    }
    return number[n];
}

int main()
{
    int number[3] = {1, 2, 3};
    int n = 3;

    nextPermutation(number, n);
    return 0;
}