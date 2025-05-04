#include <iostream>

using namespace std;
void printSum(int arr[3][4])
{
    cout << "Printing the sum" << endl;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
}
int largestSum(int arr[3][4])
{
    int largest = 0;
    int index;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += arr[i][j];
        }
        // checkpoint ...
        if (sum >= largest)
        {
            largest = sum;
            index = i; // why? used index here to reterive the row index of the largest sum of row..
        }
    }
    cout << "the largest sum is--> " << largest << "and index is" << index;
}

int main()
{

    int myarray[3][4] = {{1, 2, 3, 4}, {2, 5, 7, 6}, {9, 8, 5, 3}}; // 12 elements..
    cout << "Row wise sum-->  ";
    printSum(myarray);
    cout << endl;

    largestSum(myarray);

    return 0;
}