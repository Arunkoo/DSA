#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    // pointer p is pointing to address of a;
    int *p = &a;
    // pointer to pointer....
    int **q = &p;
    cout << "the address of &a " << &a << endl;
    cout << "The address of p " << p << endl;
    cout << "The value of p " << *p << endl;
    cout << "*q = " << *q << endl;
    cout << "**q = " << **q << endl;

    return 0;
}