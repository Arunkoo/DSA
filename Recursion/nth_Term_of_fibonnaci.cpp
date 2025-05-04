#include <iostream>
using namespace std;

// function...
int fibonnaciSeries(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int fn = fibonnaciSeries(n - 1) + fibonnaciSeries(n - 2);

    return fn;
}

int main()
{
    int n;
    cout << "Enter the number to print fibonnaci series" << endl;
    cin >> n;
    cout << fibonnaciSeries(n);
    return 0;
}