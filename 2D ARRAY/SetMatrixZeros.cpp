#include <iostream>
using namespace std;
// print function...
void print(int arr[3][4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << " " << endl;
    }
}
// setZero function....
void setZeros(int arr[3][4])
{
    // initaiallize a copy array
    int copyarr[3][4];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            copyarr[i][j] = arr[i][j];
        }
    }
    // this the logic for finding zero index and setting row and columns accordingly....
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                cout << "value of i and j" << i << j << endl;
                for (int m = 0; m < 4; m++)
                {
                    copyarr[i][m] = 0;
                }
                for (int n = 0; n < 3; n++)
                {
                    copyarr[n][j] = 0;
                }
            }
        }
    }
    // setback copy to original....
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            arr[i][j] = copyarr[i][j];
        }
    }
}
int main()
{

    int array[3][4] = {{1, 1, 2, 1}, {3, 0, 0, 2}, {1, 3, 1, 5}};
    cout << "initial array before adding zero's" << endl;

    print(array);
    setZeros(array);
    cout << "final array after adding zero's" << endl;
    print(array);
    return 0;
}