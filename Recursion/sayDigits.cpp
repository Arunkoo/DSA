#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Reverse(vector<string> arr)
{
    int first = 0;
    int last = arr.size() - 1;
    while (first < last)
    {
        swap(arr[first++], arr[last--]);
    }
    return arr;
}

vector<string> sayDigits(int n)
{
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> newArr;

    if (n == 0)
    {
        newArr.push_back("Zero");
        return newArr;
    }

    while (n > 0)
    {
        int newDigit = n % 10;
        newArr.push_back(arr[newDigit]);
        n /= 10;
    }

    return Reverse(newArr); // Reverse to maintain correct order
}

int main()
{
    int n;
    cout << "Enter the number to print in words: ";
    cin >> n;

    vector<string> words = sayDigits(n);

    for (const string &word : words)
    {
        cout << word << " ";
    }

    cout << endl;

    return 0;
}
