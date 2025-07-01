#include <iostream>
#include <queue>
using namespace std;

int main()
{
    deque<int> d;
    d.push_front(12);
    d.push_back(13);
    d.push_front(11);
    d.pop_back();

    cout << "front:- " << d.front() << endl;
    cout << "back:- " << d.back() << endl;
    return 0;
}