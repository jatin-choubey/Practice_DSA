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

void helper(node *root, vector<int> &path, int target, bool &found)
{
    if (found == true || root == NULL)
        return;

    path.push_back(root->val);
    if (root->val == target)
    {
        found = true;
        return;
    }

    helper(root->left, path, target, found);
    helper(root->right, path, target, found);
    if (found == false)
        path.pop_back();
}
vector<int> findPath(node *root, int target)
{

    vector<int> path;
    bool found = false;
    helper(root, path, target, found);
    return path;
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
    insertNode(root, 0);
    insertNode(root, 10);
    insertNode(root, 9);
    int target = 9;
    vector<int> path = findPath(root, target);

    for (auto i : path)
        cout << i << " ";
}