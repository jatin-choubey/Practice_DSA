/*
LeetCode 543. Diameter of Binary Tree   https://leetcode.com/problems/diameter-of-binary-tree/description/

Diameter is the max distance between any two leaf nodes. (Not necessarily passing through root)
*/

class Solution
{
public:
    int height(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int left = height(root->left, maxi);   // Find the height of the Left Subtree from the current Node.
        int right = height(root->right, maxi); // Find the height of the Right Subtree from the current Node.

        maxi = max(maxi, left + right); // Update the maxi if the sum of left and right are greater than maxi

        return 1 + max(left, right); // To find the height of subtree.
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        height(root, maxi);
        return maxi; // Maxi stores ans
    }
};