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
int setZeros(int arr[3][4])
{

    int zero_i;
    int zero_j;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                zero_i = i;
                zero_j = j;
                cout << "value of i and j" << i << j << endl;
                break;
            }
            continue;
        }
    }
    for (int m = 0; m < 4; m++)
    {
        arr[zero_i][m] = 0;
        // 00,01,02,03   sideways
    }
    for (int n = 0; n < 3; n++)
    {
        arr[n][zero_j] = 0;
        // 00,10,20,30 down
    }
    // cout << "Value of i and j " << zero_i << zero_j << endl;
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