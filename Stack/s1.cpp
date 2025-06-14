#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    // constructor
    Stack(int size)
    {
        this->size = size;
        arr = new int[size]; // FIXED: allocate array of size `size`
        top = -1;
    }

    // destructor to avoid memory leaks
    ~Stack()
    {
        delete[] arr;
    }

    // push method
    void push(int element)
    {
        if (top < size - 1)
        { // Check if there’s space
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    // pop method
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    // peek method
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    // check if empty
    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack st(5);
    st.push(23);
    st.push(24);

    st.pop();

    cout << st.peek();

    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
