/* LeetCode : 110. Balanced Binary Tree     https://leetcode.com/problems/balanced-binary-tree/

Given a binary tree, determine if it is height-balanced.
(A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.)

*/

class Solution
{
public:
    int Lheight(TreeNode *root) // To find the height of the Left Subtree.
    {
        if (root == NULL)
            return 0;

        return Lheight(root->left) + 1;
    }
    int Rheight(TreeNode *root) // To find the height of the Right Subtree.
    {
        if (root == NULL)
            return 0;
        return Rheight(root->right) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL || root->left == NULL && root->right == NULL) // If tree is empty or only having root node. (No left and right child)
            return true;                                               // Return True

        int left = Lheight(root);  // Height of left Subtree.
        int right = Rheight(root); // Height of Right Subtree.

        if (abs(left - right) > 1) // If the difference between the height of left and right subtree is greater than 1
        {
            return false; // Return false.
        }

        return isBalanced(root->left) && isBalanced(root->right); // Do the same for the right and left subtree.
    }
};