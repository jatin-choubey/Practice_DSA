#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
void insertNode(node *&root, int data)
{
    node *newNode = new node(data);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    node *temp = root;

    while (true)
    {
        if (newNode->val <= temp->val)
        {
            if (temp->left != NULL)
            {
                temp = temp->left;
            }
            else
            {
                temp->left = newNode;
                return;
            }
        }
        else
        {
            if (temp->right != NULL)
            {
                temp = temp->right;
            }
            else
            {
                temp->right = newNode;
                return;
            }
        }
    }
}
void preorder(node *root)
{
    if (root)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
void postorder(node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}
void levelorder(node *root)
{
    if (root == NULL)
    {
        cout << -1;
        return;
    }

    queue<node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        int size = Q.size();

        for (int i = 0; i < size; i++)
        {
            node *FRONT = Q.front();

            if (FRONT->left)
                Q.push(FRONT->left);

            if (FRONT->right)
                Q.push(FRONT->right);

            cout << FRONT->val << " ";
            Q.pop();
        }
        cout << endl;
    }
}
void iterative_PreOrder(node *root)
{
    if (root == NULL)
    {
        cout << -1;
        return;
    }
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *top = st.top();
        cout << top->val << " ";
        st.pop();
        if (top->right)
            st.push(top->right);
        if (top->left)
            st.push(top->left);
    }
}
void iterative_InOrder(node *root)
{
    if (root == NULL)
    {
        cout << -1;
        return;
    }
    stack<node *> st;

    node *temp = root;
    while (true)
    {
        if (temp)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty())
                break;
            temp = st.top();
            cout << temp->val << " ";
            st.pop();
            temp = temp->right;
        }
    }
}
void iterative_PostOrder(node *root)
{
    if (root == NULL)
    {
        cout << -1;
        return;
    }
    stack<node *> s1;
    stack<node *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        node *top = s1.top();
        s1.pop();
        s2.push(top);

        if (top->left)
        {
            s1.push(top->left);
        }

        if (top->right)
        {
            s1.push(top->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}
int main()
{
    node *root = NULL;
    insertNode(root, 3);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 7);

    cout << "PRE\n";
    preorder(root);

    cout << "\nIN\n";
    inorder(root);

    cout << "\nPOST\n";
    postorder(root);

    cout << "\nLEVEL\n";
    levelorder(root);

    cout << "Iterative PRE\n";
    iterative_PreOrder(root);

    cout << "\nIterative IN\n";
    iterative_InOrder(root);

    cout << "\nIterative POST\n";
    iterative_PostOrder(root);

    return 0;
}