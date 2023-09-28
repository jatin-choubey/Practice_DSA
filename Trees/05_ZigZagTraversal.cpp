/*
103. Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right,
then right to left for the next level and alternate between).



Example 1:
Input: root = [3,9,20,null,null,15,7]
            3
           / \
          9  20
            /  \
           15  7

Output: [[3],[20,9],[15,7]]
*/

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};

        queue<TreeNode *> Q;
        vector<vector<int>> ans;

        // Pushing in the Level 1 or the Root in the Queue and Answer Data Structures.
        Q.push(root);
        ans.push_back({root->val});

        int level = 2; // Starting to check from the level 2.
        while (!Q.empty())
        {
            int qSize = Q.size();
            vector<int> op;

            while (qSize != 0)
            {
                TreeNode *top = Q.front();
                if (top->left) // Pushing in Left Child if it exists
                {
                    op.push_back(top->left->val);
                    Q.push(top->left);
                }
                if (top->right) // Pushing in Right Child if it exists
                {
                    op.push_back(top->right->val);
                    Q.push(top->right);
                }
                Q.pop();
                qSize--;
            }

            // If the level was Even, reverse the output we got from this level, as the even levels are stored from right to left.
            if (level % 2 == 0)
                reverse(op.begin(), op.end());

            if (op.size() != 0) // To ignore the case where there were no leaf nodes, and hence the output vector remained empty.
                ans.push_back(op);

            level++; // Go to the next level
        }
        return ans;
    }
};