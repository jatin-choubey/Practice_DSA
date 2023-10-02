/*
Write a program to get the Right or Left View of a Binary Tree
A Right or Left view of a Binary Tree is the set of nodes that are visible when the tree is viewd from the
Right Side or the Left Side respectively.

            1
          /   \
        2      3
      /  \    / \
     4   5   6   7
        /
      8

    Right View = 1, 3, 7, 8

    Left View = 1, 2, 4, 8
*/

// ---------   (Recursive PreOrder Traversal) -------------
// TC = O(N),
/*SC = O(N)
(Auxillary Stack Space)
(Will be storing height of Tree elements at a time)
(Worst Case : Skewed Tree)*/

class Solution
{
public:
    // Helper function to perform Reverse Pre-Order Traversal to obtain the Right View of the Binary Tree.
    // We can do normal PreOrder for Left View
    void reversePreOrder(TreeNode *root, int level, vector<int> &ans)
    {
        if (root == NULL)
            return;

        // If the current level is equal to the size of the answer vector,
        // it indicates that we are visiting the rightmost node at this level,
        // considering it as the root node for this level.
        // Therefore, we add it to the answer vector.
        // Subsequently, the size of the answer vector increases, and this condition
        // won't be satisfied for any other node at the same level, ensuring we capture
        // only the rightmost node of each level.
        if (level == ans.size())
            ans.push_back(root->val);

        // Visit the Right Node first to explore the right subtree.
        reversePreOrder(root->right, level + 1, ans);

        // Then Visit the Left Node to explore the left subtree.
        reversePreOrder(root->left, level + 1, ans);
    }

    // Main function to obtain the right side view of the Binary Tree.
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;               // Vector to store the right side view elements
        reversePreOrder(root, 0, ans); // Start traversal with the root node at level 0
        return ans;
    }
};

// ------------ (Iterative Level Order Traversal) ---------------
// TC = O(N)
/*
SC = O(N)
(Queue Data Strucutre : Will be storing width of each level at a time, like, 1 node, 2 node, 4 node, 8 node ...)
(Worst Case : Tree is a Complete BT, in which the case the SC = O(Elements in Last Level) ie O(N/2))
*/
class Solution
{
public:
    // Function to obtain the right side view of a Binary Tree using Level Order Traversal.
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == NULL)
            return {}; // Return an empty vector if the tree is empty.

        vector<int> ans;                // Vector to store the right side view elements.
        queue<pair<TreeNode *, int>> Q; // Queue data structure to store nodes and their levels.
        Q.push({root, 0});              // Push the root node along with its level to initiate Level Order Traversal.

        while (!Q.empty()) // Continue looping until the queue is empty.
        {
            int size = Q.size();
            int sawRight = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = Q.front().first;
                int level = Q.front().second;
                Q.pop();

                if (node->right) // If the right child exists, push it into the queue along with its level.
                    Q.push({node->right, level + 1});

                if (node->left) // If the left child exists, push it into the queue along with its level.
                    Q.push({node->left, level + 1});

                if (sawRight == 0) // If sawRight is 0, it means we haven't seen any element from the right side at this level yet,
                {                  // so we add the front element of the queue to the answer vector, indicating the rightmost node at this level.
                    ans.push_back(node->val);
                    sawRight = 1; // Update sawRight to 1 to indicate that we have seen a right-side element at this level.
                }
            }
        }
        return ans; // Return the right side view elements.
    }
};
