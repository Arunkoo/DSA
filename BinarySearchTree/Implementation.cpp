#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
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
Node *insertIntoBst(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertIntoBst(root->right, d);
    }
    else
    {
        root->left = insertIntoBst(root->left, d);
    }

    return root;
}
void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int minVal(Node *&root)
{
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}
int maxVal(Node *&root)
{
    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp->data;
}
void InsertData(Node *&root)

{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}
// inorder predessor and successor...
int InorderPredessor(Node *&root, int val)
{
    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == val)
            cout << "No predessor found" << endl;
        // left...
        if (val < temp->data)
        {
            if (temp->left->data == val)
                return temp->data;
            else
                temp = temp->left;
        }
        else
        {
            if (temp->right->data == val)
                return temp->data;
            else
                temp = temp->right;
        }
    }
}
int InorderSuccessor(Node *&root, int val)
{
    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == val)
            cout << "No predessor found" << endl;
        // left...
        if (val < temp->data)
        {
            if (temp->left->data == val)
                return temp->left->data;
            else
                temp = temp->left;
        }
        else
        {
            if (temp->right->data == val)
                return temp->right->data;
            else
                temp = temp->right;
        }
    }
}
// Delete in BST....
Node *deleteNode(Node *root, int val)
{
    if (!root)
        return NULL;

    if (val < root->data)
    {
        // Go left
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        // Go right
        root->right = deleteNode(root->right, val);
    }
    else
    {
        // Node to be deleted found

        // Case 1: 0 children
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // Case 2: 1 child
        if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: 2 children
        // Replace with min value in right subtree
        int mini = minVal(root->right);
        root->data = mini;
        // Delete that min node from right subtree
        root->right = deleteNode(root->right, mini);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data for the Binary Search Tree (BST): " << endl;
    InsertData(root);
    cout << "Traversing binary search tree" << endl;
    levelOrderTraversal(root);

    // cout << "Printing Inorder---->" << endl;
    // Inorder(root);
    // cout << endl;

    // root = deleteNode(root, 50);
    // cout << "Traversing binary search tree" << endl;
    // levelOrderTraversal(root);

    // cout << "Printing Inorder---->" << endl;
    // Inorder(root);

    // cout << "maxValue of BST --> ";
    // cout << maxVal(root);
    // cout << endl;
    // cout << "minValue of BST --> ";
    // cout << minVal(root);
    // cout << endl;
    //
    // cout << "Inorder predessor--->";
    // cout << InorderPredessor(root, 3);
    // cout << endl;
    // cout << "Inorder Succesor--->";
    // cout << InorderSuccessor(root, 3);
    return 0;
}