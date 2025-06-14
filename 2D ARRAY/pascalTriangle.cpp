#include <iostream>
using namespace std;

void BinomialCoff(int n, int k)
{
}

void generatePascalTriangle(int rows)
{

    for (int i = 0; i < rows; i++)
    {
        // Print spaces for alignment
        for (int space = 1; space <= rows - i; space++)
        {
            cout << "  ";
        }

        int number = 1;
        for (int j = 0; j <= i; j++)
        {
            cout << "   " << number;
            number = number * (i - j) / (j + 1);
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of rows:-> " << endl;
    cin >> n;

    generatePascalTriangle(n);

    return 0;
}