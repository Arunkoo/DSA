#include <iostream>
using namespace std;

// functions..
bool isPalindrome(string str, int s, int e)
{
    // base
    if (s >= e)
    {
        return true;
    }

    if (str[s] != str[e])
    {
        return false;
    }

    return isPalindrome(str, s + 1, e - 1);
}
int main()
{
    string String;
    int s, e;
    cout << "Enter the string to check if it is palindrome or not " << endl;
    cin >> String;

    if (isPalindrome(String, 0, String.length() - 1))
        cout << "Yes, it's a palindrome!" << endl;
    else
        cout << "No, it's not a palindrome." << endl;

    return 0;
}