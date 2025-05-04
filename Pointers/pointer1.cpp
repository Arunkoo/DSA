#include <iostream>
using namespace std;

int main()
{
    int num = 6;
    int *p = &num;

    (*p)++;
    cout << "the value of *p " << *p << endl;
    cout << "the value of num" << num << endl;

    // copying a pointer ....
    int *q = p;

    cout << p << "-" << q << endl;

    // arithmetic operation with pointer .....

    int i = 3;

    int *t = &i;

    int f = *t + *q;

    cout << "f = " << f << endl;

    cout << t << endl;

    t = t + 1;
    cout << t;

    return 0;
}