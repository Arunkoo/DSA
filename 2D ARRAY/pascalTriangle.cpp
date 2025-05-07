#include <iostream>
using namespace std;

void generatePascalTriangle(int rows)
{

    for (int i = 1; i <= rows; ++i)
    {
        // Print spaces
        for (int space = 1; space <= rows - i; ++space)
        {
            cout << " ";
        }

        // Print stars
        for (int j = 1; j <= 2 * i - 1; ++j)
        {
            cout << j;
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