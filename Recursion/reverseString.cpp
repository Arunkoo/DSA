#include <iostream>
#include <vector>
using namespace std;

// function....
void reverseString(string &name, int s, int e)
{
    // base case...aru
    if (s >= e)
        return;
    swap(name[s], name[e]);
    reverseString(name, s + 1, e - 1);
}

int main()
{
    string name;
    int s;
    int e;
    cout << "Enter a string to reverse --> ";
    cin >> name;

    reverseString(name, s = 0, e = name.length() - 1);
    cout << "Reversed string --> " << name << endl;

    return 0;
}