class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = maxDepth(root->left);   // Find the height of left Subtree
        int rightHeight = maxDepth(root->right); // Find the height of the right Subtree

        return 1 + max(leftHeight, rightHeight); // Taking the Max among the Right and Left Subtree Height, and adding 1 to it to incldue the height of the root itself.
    }
};