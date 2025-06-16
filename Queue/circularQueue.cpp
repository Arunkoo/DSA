#include <iostream>
using namespace std;

class circularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    circularQueue(int k)
    {
        this->size = k;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int data)
    {
        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
        {
            return false; // Queue is full
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = data;
        return true;
    }

    bool dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is already empty!" << endl;
            return false;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return true;
    }

    int Front()
    {
        if (front == -1)
            return -1;
        return arr[front];
    }

    int Rear()
    {
        if (rear == -1)
            return -1;
        return arr[rear];
    }

    bool is_Empty()
    {
        return front == -1;
    }
};

int main()
{
    circularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    q.dequeue();

    cout << "After dequeue, Front: " << q.Front() << endl;

    return 0;
}
