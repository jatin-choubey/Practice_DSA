/* 987. Vertical Order Traversal of a Binary Tree https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

NOTE: Please Visit the code using the Above link for clear understanding of Code.


Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1)
and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column
index starting from the leftmost column and ending on the rightmost column. There may be multiple
nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.


*/

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // A data structure to Map Vertical with Level, and level with node values.
        map</*vertical*/ int, map</*level*/ int, /*values*/ multiset<int>>> ds;

        // Storing the Node, Level and Vertical in the Queue for the Level Order Traversal
        queue<pair</*Node*/ TreeNode *, pair</*level*/ int, /*vertical*/ int>>> Q;

        Q.push({root, {0, 0}}); // Store the Root node, its level (ie 0) and its Vertical (ie 0) to start the level order traversal

        while (!Q.empty())
        {
            pair<TreeNode *, pair<int, int>> top = Q.front();
            Q.pop();

            TreeNode *node = top.first;       // The front node in Queue
            int level = top.second.first;     // Level of the Front Node.
            int vertical = top.second.second; // Vertical of the Front node

            ds[vertical][level].insert(node->val); // Map the front node's value with its vertical and level and store it into the map data structure.

            if (node->left)                                      // If left of front is not NULL
                Q.push({node->left, {level + 1, vertical - 1}}); // Add left node to the Queue, along with its vertical and level. (Vertical will decrease by 1 when going left)

            if (node->right)                                      // If Right of front is not NULL
                Q.push({node->right, {level + 1, vertical + 1}}); // Add Right node to the Queue, along with its vertical and level. (Vertical will increase by 1 when going Right)
        }

        vector<vector<int>> ans;

        // Now store the values present in the Map ds into the 'ans' vector
        for (auto &i : ds)
        {
            vector<int> op;
            for (auto &j : i.second)
            {
                op.insert(op.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(op);
        }

        // Return ans
        return ans;
    }
};
