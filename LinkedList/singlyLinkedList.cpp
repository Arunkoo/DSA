#include <iostream>
using namespace std;

// class node...
class Node
{
public:
    int data;
    Node *next;
    // constructor..
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// Insertion at head..
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
// Insertion at tail..
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
// Insertion at middle...
void insertAtMiddle(Node *&head, int d, int position)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *nodeToinsert = new Node(d);
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}
// Delete a node...
void deleteNode(Node *&head, int value)
{
    // for empty linked list...
    if (head == NULL)
    {
        return;
    }
    // if head is itself a value that is needed to be deleted...
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    // now need to traverse through whole list...
    Node *prev = NULL;
    Node *curr = head;
    // traversing means finding the wirte value  and breaking the loop...
    while (curr != NULL && curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    // if value is not found...
    if (curr == NULL)
    {
        return;
    }

    // deleting a node...
    prev->next = curr->next;
    delete curr;
}
// void print function..
void printLinkedList(Node *&head)
{
    Node *temp = head;
    cout << "Current value of Linked List--> ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// ...................//.................///...............//
main()
{
    Node *node1 = new Node(10);
    // head pointed to node1;
    Node *head = node1;
    // Tail pointed to node1;
    Node *tail = node1;
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtTail(tail, 3);
    insertAtHead(head, 8);
    insertAtTail(tail, 9);
    printLinkedList(head);
    insertAtMiddle(head, 7, 2);

    printLinkedList(head);
    insertAtMiddle(head, 7, 1);
    printLinkedList(head);
    insertAtMiddle(head, 12, 5);
    printLinkedList(head);
    cout << "performing deletion" << endl;
    deleteNode(head, 12);
    deleteNode(head, 7);
    cout << "Linked list after deletion" << endl;
    printLinkedList(head);

    cout
        << "currentHead " << head->data << endl;

    cout << "currentTail " << tail->data << endl;

    return 0;
}