#include <iostream>

using namespace std;
// functions...

int PowerofTwo(int n)
{
    // base case ..
    if (n == 0)
    {
        return 1;
    }

    int smallCase = PowerofTwo(n - 1);
    int bigCase = 2 * smallCase;
    return bigCase;
}
int main()
{
    int n;

    cout << "Type down value of n  to get 2^n " << endl;
    cin >> n;
    cout << "2^" << n << " is " << PowerofTwo(n) << endl;

    return 0;
}