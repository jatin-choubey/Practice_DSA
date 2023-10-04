/*
C++ code to find the path of the given target node from the Root Node.

            3
          /  \
        2     5
      /     /  \
    1     4     8
  /           /  \
0            6    9
              \    \
               7    10

Target Node = 6

Output = [3, 5, 8, 6]
*/

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

// ------------- Main Logic Begins here --------------------
void myLogic(node *root, vector<int> &path, int target, bool &found)
{
    if (found == true || root == NULL)
        return;

    path.push_back(root->val);
    if (root->val == target)
    {
        found = true;
        return;
    }

    myLogic(root->left, path, target, found);
    myLogic(root->right, path, target, found);
    if (found == false)
        path.pop_back();
}
bool striverLogic(node *root, vector<int> &path, int target)
{
    if (root == NULL)
        return false;

    path.push_back(root->val);

    if (root->val == target)
        return true;

    bool foundLeft = striverLogic(root->left, path, target);
    bool foundRight = striverLogic(root->right, path, target);

    if (foundLeft || foundRight)
        return true;

    path.pop_back();
    return false;
}
vector<int> findPath(node *root, int target)
{

    vector<int> path;
    bool found = false;
    striverLogic(root, path, target);
    vector<int> path2;
    myLogic(root, path2, target, found);
    return path2;
}
int main()
{
    node *root = NULL;
    insertNode(root, 3);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 8);
    insertNode(root, 6);
    insertNode(root, 0);
    insertNode(root, 7);
    insertNode(root, 9);
    insertNode(root, 10);

    int target = 6;

    vector<int> path = findPath(root, target);

    for (auto i : path)
        cout << i << " ";
}