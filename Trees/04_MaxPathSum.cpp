/*
LeetCode 124. Binary Tree Maximum Path Sum  https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum 'path sum' of any 'non-empty' path.
*/

class Solution
{
public:
    // Helper function to calculate the maximum path sum
    int helper(TreeNode *root, int &sum, int maxi)
    {
        // If the node is null, return 0
        if (root == NULL)
            return 0;

        // Recursively call the helper function for the left and right child of the node
        int left = helper(root->left, sum, maxi);
        int right = helper(root->right, sum, maxi);

        // This is Done to store the Maximum Path Sum that can be obtained via passing through this particular node.
        sum = max(sum, left + right + root->val);

        // The below two lines are basically helps to find if we will pass our path from the left subtree or right subtree or just consider root or neither of them and just 0.

        int leftVal = root->val + left;   // Calculate the sum of the node value and its left child
        int rightVal = root->val + right; // Calculate the sum of the node value and its right child

        // Suppose the leftVal is 5 and rightVal is 2, we will consider rightVal as maxi.
        // If root leftVal = -1, rightVal = -4, and root is 5, we will simply take just the root.
        // If all three are negative values, we will take '0' as maxi, which means, we are not taking any path in the particular subtree.
        maxi = max(0, (max(root->val, max(leftVal, rightVal))));

        // Return maxi
        return maxi;
    }
    // Function to calculate the maximum path sum in a binary tree
    int maxPathSum(TreeNode *root)
    {
        // Initialize sum and maxi to be the value of the root node
        int sum = root->val;
        int maxi = root->val;

        // Call the helper function with root, sum and maxi as arguments
        helper(root, sum, maxi);

        // Return sum as the maximum path sum
        return sum;
    }
};
