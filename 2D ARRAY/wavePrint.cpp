#include <iostream>
using namespace std;

int wavePrint(int arr[3][4], int Rows, int Cols)
{
    for (int col = 0; col < Cols; col++)
    {
        // odd we are going from bottom top...
        if (col % 2 != 0)
        {
            for (int row = Rows - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            // for even col..
            for (int row = 0; row < Rows; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
    }
}

int main()
{
    int myarray[3][4] = {{1, 2, 3, 4}, {2, 5, 7, 6}, {9, 8, 5, 3}};

    wavePrint(myarray, 3, 4);

    return 0;
}