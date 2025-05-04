#include <iostream>
using namespace std;

// factorial function...
int Factorial(int n)
{

    // base..
    if (n == 0)
    {
        return 1;
    }

    // recursive function..
    int smallProblem = Factorial(n - 1);
    int bigProblem = n * smallProblem;

    return bigProblem;
}

int main()
{
    int n;

    cout << "Enter a number to find factorial of" << endl;
    cin >> n;

    cout << "factorial of " << n << " is " << Factorial(n) << endl;
}