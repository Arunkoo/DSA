#include <iostream>
#include <math.h>
using namespace std;
// function..
int a_ToPower_b(int a, int b)
{
    // int ans = 1;
    // for (int i = 1; i <= b; i++)
    // {
    //     ans = ans * a;
    // }
    // return ans;

    // using recursion...
    if (b == 0)
    {
        return 1;
    }
    return a * a_ToPower_b(a, b - 1);
}

int main()
{
    int a, b;
    cout << "Enter the value of a " << endl;
    cin >> a;
    cout << "Enter the value of b" << endl;
    cin >> b;

    cout << a_ToPower_b(a, b);

    return 0;
}