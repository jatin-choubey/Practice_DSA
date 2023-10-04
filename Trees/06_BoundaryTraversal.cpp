/*
Traverse and Print Boundary of a Binary Tree

Input = 3, 2, 1, 5, 4, 6, 7

            3
          /   \
        2      5
      /       / \
    1        4   6
                  \
                   7

    Output = 3 2 1 4 7 6 5

*/

// Checking if the Current Element is the Root Node.
bool isLeaf(node *root)
{
    return (root->left == NULL && root->right == NULL);
}

// To traverse the Left Boundary Elements
void addLeftBoundary(node *root, vector<int> &ans)
{
    node *curr = root->left;
    while (curr != NULL)
    {
        if (!isLeaf(curr)) // Store in answer if its not the Leaf Node.
        {
            ans.push_back(curr->val);
        }

        if (curr->left)
            curr = curr->left; // Keep Going Left till its not NULL
        else
            curr = curr->right; // If left is NULL, go to the Right
    }
}

// To traverse the Right Boundary Elements
void addrightBoundary(node *root, vector<int> &ans)
{
    node *curr = root->right;
    stack<int> st; // Using stack to store the visited node because we want to finally store them for the Right boundary from Bottom to Top
    while (curr)
    {
        if (!isLeaf(curr)) // only add in Stack if its not the Leaf Node.
        {
            st.push(curr->val);
        }

        if (curr->right)
            curr = curr->right; // Keep going Right till its not NULL
        else
            curr = curr->left; // If right is NUll, go the Left
    }

    // Add all the Stack Element from in the answer vector. (This makes sure that we are storing the visited nodes from bottom of tree to the top)
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}

// If its a leaf Node. Do a Left to Right traversal (Inorder)
void addLeaf(node *root, vector<int> &ans)
{
    // Only add in answer vector if its a Leaf Node.
    if (isLeaf(root))
    {
        ans.push_back(root->val);
        return;
    }

    if (root->left) // Go to the Left of the root
        addLeaf(root->left, ans);

    if (root->right) // Go the right of the root
        addLeaf(root->right, ans);
}

// Given Function to traverse and print the boundary of the Tree.
vector<int> printBoundary(node *root)
{
    vector<int> ans;

    if (!isLeaf(root)) // If the root value itself is leaf, still no need to push it answer, as the addLeaf function will do it.
        ans.push_back(root->val);

    addLeftBoundary(root, ans);  // First we visit the left boundary
    addLeaf(root, ans);          // Then we visit all the Leaf Nodes
    addrightBoundary(root, ans); // Then lastly we visit the right Boundary

    return ans;
}