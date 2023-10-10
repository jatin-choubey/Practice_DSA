/*  LeetCode 236 : Lowest Common Ancestor  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between
two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a
node to be a descendant of itself).

Input-> p = 4, q = 7
            3
          /  \
        2     5
      /     /  \
    1     4     8
  /           /  \
0            6    9
              \    \
               7    10

ouptput : Lowest Common Ancestor (LCA) = 5

Input-> p = 10, q = 8 (Same Tree as above)
Output = 8 (A node can even be its own ancestor(Not sure how or why, but 'It is What it Is', according to rule))

********************************************************************************************/

// Approach 1 : Store the Path from the Root node to the node 'p' and node 'q' respectively. (Exact same we did in previous question No. 12)
/*
for eg : p = 4, q = 7

p_path = [3, 5, 4]
q_path = [3, 5, 8, 6, 7]

Now place one iterator each (say i and j) at the start of both the Path Vectors, and the last element that is found to be the same in both of
the vectors, is our answer.
= 5 in this case.
*/

class Solution
{
public:
    void myLogic(TreeNode *root, vector<TreeNode *> &path, int target, bool &found)
    {
        if (found == true || root == NULL)
            return;

        path.push_back(root);
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        bool found = false;
        vector<TreeNode *> p_path; // To store the path from the Root node to the node 'p'.
        myLogic(root, p_path, p->val, found);

        vector<TreeNode *> q_path; // To store the path form the Root node to the node 'q'.
        found = false;
        myLogic(root, q_path, q->val, found);

        int i = 0, j = 0;
        TreeNode *ans = NULL;
        while (i < p_path.size() && j < q_path.size())
        {
            if (p_path[i] == q_path[j])
                ans = p_path[i];
            else
                break; // The moment both the path elements differ, break.
            i++;
            j++;
        }
        return ans;
    }
};

/**********************************************************8
Approach 2 :
*/

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // Base case: If the root is NULL, there's no common ancestor.
    if (root == NULL)
        return NULL;

    // If the current root's value matches either p or q, it's a common ancestor.
    if (root->val == p->val || root->val == q->val)
        return root;

    // Recursively search for p and q in the left and right subtrees.
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    // Check if both p and q are found in different subtrees.
    if (left && right)
        return root; // The current root is the lowest common ancestor.

    // If one of p or q is found in the left subtree, return it.
    else if (left && !right)
        return left;

    // If one of p or q is found in the right subtree, return it.
    else if (!left && right)
        return right;

    // If neither p nor q is found in this subtree, return NULL.
    else
        return NULL;
}
