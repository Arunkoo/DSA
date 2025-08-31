#include <iostream>
#include <queue>
using namespace std;

// data strucure...

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// createBinaryTree function...
Node *createBinaryTree(Node *root)
{
    // take input..
    cout << "Enter the data to build tree--> " << endl;
    int val;
    cin >> val;

    root = new Node(val);

    if (val == -1)
    {
        return NULL;
    }
    else
    {
        // recursively build tree..
        cout << "Enter left data--> ";
        root->left = createBinaryTree(root->left);
        cout << "Enter right data--> ";
        root->right = createBinaryTree(root->right);

        return root;
    }
}

// print the tree by level order traversing...
void levelOrderTraverse(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // for tracking we used NULL flag in queue...

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }
}

// printing Inorder...  LNR...

void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data;
    Inorder(root->right);
}

// building tree from level order...
void BuildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter a data to build tree--> " << endl;
    int val;
    cin >> val;

    root = new Node(val);
    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        ///// creaeting left Node and pushing it...
        cout << "Enter the left of " << frontNode->data << endl;
        int leftVal;
        cin >> leftVal;

        if (leftVal != -1)
        {
            frontNode->left = new Node(leftVal);
            q.push(frontNode->left);
        }

        //////creating right node and pushing in root->right..
        cout << "Enter the right data " << frontNode->data << endl;
        int rightVal;
        cin >> rightVal;

        if (rightVal != -1)
        {
            frontNode->right = new Node(rightVal);
            q.push(frontNode->right);
        }
    }
}

int main()
{

    // base root...
    Node *root = NULL;

    BuildFromLevelOrder(root);

    cout << "Printing the data in levelOrder traversing...> " << endl;
    levelOrderTraverse(root);
    cout << endl;
    cout << "Printing the data in levelOrder traversing...> " << endl;
    Inorder(root);

    return 0;
}