#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(23);
    cout << "queue:" << q.front() << endl;
    return 0;
}