#include <iostream>
using namespace std;
// print function...
void print(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << " " << endl;
    }
}
// setZero function....
int setZeros(int arr[3][3])
{
    int zero_i = 0;
    int zero_j = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                zero_i = i;
                zero_j = j;
            }
        }
    }
    for (int m = 0; m < 3; m++)
    {
        arr[zero_i][m] = 0;
    }
    for (int n = 0; n < 3; n++)
    {
        arr[n][zero_j] = 0;
    }
    // cout << "Value of i and j " << zero_i << zero_j << endl;
}
int main()
{
    int array[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 0, 1}};
    cout << "initial array before adding zero's" << endl;

    print(array);
    setZeros(array);
    cout << "final array after adding zero's" << endl;
    print(array);
    return 0;
}