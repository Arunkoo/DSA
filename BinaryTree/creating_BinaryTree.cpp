#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data in left side: " << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data in right side: " << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

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

void reverseOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    stack<node *> s;

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        s.push(temp);

        // 🔁 IMPORTANT: Push right first, then left
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }

    // Now print the reverse level order
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

// Inorder traversal...
void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // defination for inorder L N R...
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// preOrder traversal....
void PreOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // defination  for preOrder N L R..
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// PostOrder traversal...
void PostOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // defination for postorder ... L R N..
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

// building a tree from level order traversing...
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter a data in root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter the data to left of root " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the data to right of root " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    node *root = NULL;
    //   1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    // root = buildTree(root);
    // cout << "Printing the level order traversal output" << endl;
    // levelOrderTraversal(root);
    // cout << "Printing the reverse level order traversal output" << endl;
    // reverseOrderTraversal(root);

    // cout << "Printing Inorder traversal:----> " << " ";
    // Inorder(root);
    // cout << endl;
    // cout << "Printing PreOrder traversal:----> " << " ";
    // PreOrder(root);
    // cout << endl;
    // cout << "Printing PostOrder traversal:----> " << " ";
    // PostOrder(root);

    buildFromLevelOrder(root);
    cout << "Printing the level order traversal output" << endl;
    levelOrderTraversal(root);

    return 0;
}