#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *createTree(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    // check data...
    if (d < root->data)
    {
        root->left = createTree(root->left, d);
    }
    else
    {
        root->right = createTree(root->right, d);
    }

    return root;
}

void InsertData(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = createTree(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// return max and min value...

int maxVal(Node *&root)
{
    Node *temp = root;

    while (temp->right != NULL)
    {

        temp = temp->right;
    }
    return temp->data;
}
int minVal(Node *&root)
{
    Node *temp = root;

    while (temp->left)
    {
        temp = temp->left;
    }
    return temp->data;
}

// deletion of the node in the bst...
void deleteNode(Node *root, int d)
{
}
int main()
{
    Node *root = NULL;
    cout << "Enter the data to make bst" << endl;
    InsertData(root);

    cout << "Printing the tree data" << endl;
    levelOrderTraversal(root);

    cout << "Printing the maximum val:  " << endl;
    cout << maxVal(root);

    cout << endl;

    cout << "Printing the minimum val:  " << endl;
    cout << minVal(root);

    cout << "delete a node: " << endl;
    deleteNode(root, 10);
    return 0;
}