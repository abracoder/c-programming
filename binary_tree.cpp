#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
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
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << "  ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    preorder(root->left);

    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);

    postorder(root->right);
    cout << root->data << "  ";
}

node *buildBinaryTree(node *&root)
{
    int data;
    cout << "enter the data" << endl;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter data for left of " << data << endl;
    root->left = buildBinaryTree(root->left);

    cout << "enter data for right of  " << data << endl;
    root->right = buildBinaryTree(root->right);

    return root;
}

int main()
{

    node *root = NULL;

    root = buildBinaryTree(root);

    cout << "level order traveseral of treee" << endl;
    levelOrderTraversal(root);
    // 5 4 2 0 -1 -1 -1 1 -1 -1 3 2 -1 -1 4 -1 -1

    cout << endl
         << "inorder traversal of tree " << endl;
    inorder(root);
    cout << endl
         << "preorder traversal of tree" << endl;
    preorder(root);

    cout << endl
         << "post order traversal of tree" << endl;

    postorder(root);
    return 0;
}
