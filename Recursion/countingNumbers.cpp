#include <iostream>
using namespace std;
// function for counting..

int countNumber(int n)
{
    // base case..
    if (n == 0)
        return;

    cout << n;
    int call = countNumber(n - 1);
    return call;
}

int main()
{
    int n;

    cout << "Enter the number to print counting" << endl;
    cin >> n;
    countNumber(n);
    return 0;
}