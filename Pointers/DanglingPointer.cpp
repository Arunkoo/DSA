#include <iostream>
using namespace std;
// finctional call...
int *fun()
{
    int x = 10;
    return &x;
}
// deallocation of memory...
int main()
{
    int *p = fun();
    // p points to something which is not
    // valid anymore
    cout << *p;
    return 0;
}