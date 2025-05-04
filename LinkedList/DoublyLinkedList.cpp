#include <iostream>
using namespace std;

// class node..
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
// print linked list...
void printLinkedList(Node *&head)
{
    Node *temp = head;
    cout << "Printing a current linkedlist--> ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// getLength...
int getLength(Node *&head)

{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
// Insert at head function...
void insertAtHead(Node *&head, int d)
{
    // create a node..
    Node *nodeToinsert = new Node(d);
    Node *temp = head;
    nodeToinsert->next = temp;
    temp->prev = nodeToinsert;
    head = nodeToinsert;
}
// insert at tail function...
void insertAtTail(Node *&tail, int d)
{
    // create a new node...
    Node *nodeToinsert = new Node(d);
    Node *temp = tail;
    nodeToinsert->prev = temp;
    temp->next = nodeToinsert;
    tail = nodeToinsert;
}
// insertAtmiddle...
void insertAtmiddle(Node *&head, Node *&tail, int d, int position, int &length)
{
    int cnt = 1;

    // insert at head if length is 1...
    if (length == 1)
    {
        insertAtHead(head, d);
    }
    // out of length condition...
    if (position > length)
    {
        cout << "Error cannot insert value out of length" << endl;
    }
    // create a new node to insert in middle..
    Node *temp1 = head;
    Node *temp2 = NULL;
    while (cnt < position - 1)
    {
        temp1 = temp1->next;
        temp2 = temp1->next;
        cnt++;
    }
    Node *nodeToinsert = new Node(d);
    temp1->next = nodeToinsert;
    nodeToinsert->next = temp2;
    temp2->prev = nodeToinsert;
    nodeToinsert->prev = temp1;
    length++;
}
// Delete a node...
void deleteAtHead(Node *&head, int value, int &Length)
{
    Node *temp = head;
    if (temp->data == value)
    {
        head = temp->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        Length--;
    }
}
void deleteByValue(Node *&head, Node *&tail, int value, int &length)
{
    if (!head)
        return; // Edge Case: Empty list

    Node *temp = head;

    // Traverse the DLL to find the node with the given value
    while (temp && temp->data != value)
    {
        temp = temp->next;
    }

    if (!temp)
        return; // Edge Case: Value not found

    // Case 1: Node to be deleted is the **head**
    if (temp == head)
    {
        head = temp->next;
        if (head)
            head->prev = nullptr;
    }

    // Case 2: Node to be deleted is the **tail**
    if (temp == tail)
    {
        tail = temp->prev;
        if (tail)
            tail->next = nullptr;
    }

    // Case 3: Node is in the **middle**
    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp; // Free memory
    length--;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    // calls...
    // cout << "executing a insert function" << endl;
    insertAtHead(head, 20);
    insertAtTail(tail, 30);
    printLinkedList(head);
    // length calculation...
    int length = getLength(head);
    cout << "intialLength-->" << length << endl;
    cout << "Processing a function" << endl;
    insertAtmiddle(head, tail, 40, 3, length);
    insertAtmiddle(head, tail, 0, 3, length);
    deleteByValue(head, tail, 0, length);

    // cout << "perform succesfully" << endl;
    printLinkedList(head);

    cout << "currentHead-->" << head->data << endl;
    cout << "currentTail-->" << tail->data << endl;
    cout << "finalLength-->" << length;

    return 0;
}