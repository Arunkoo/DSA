#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int frontIdx;
    int rearIdx;
    int size;

public:
    Queue()
    {
        size = 5;
        arr = new int[size];
        frontIdx = 0;
        rearIdx = 0;
    }

    void enqueue(int data)
    {
        if (rearIdx == size)
        {
            cout << "Queue is full!" << endl;
        }
        else
        {
            arr[rearIdx++] = data;
        }
    }

    int dequeue()
    {
        if (frontIdx == rearIdx)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else
        {
            int ans = arr[frontIdx++];
            if (frontIdx == rearIdx)
            {
                frontIdx = 0;
                rearIdx = 0;
            }
            return ans;
        }
    }

    int getFront()
    {
        if (frontIdx == rearIdx)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIdx];
    }

    bool isEmpty()
    {
        return frontIdx == rearIdx;
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(15);

    cout << q.getFront() << endl;

    return 0;
}
