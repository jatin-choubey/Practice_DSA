/*   Vertical Level

What will the tree look like, when viewed from Top
(Left to Right)

eyes looking from top
        ||
        V

        0
      /  \
     1    2
   /  \    \
  3    4    5
      / \
     6   7

Output = 3, 1, 0, 2, 5
*/

// Approach :
// Using the Level Order Traversal and Ordered Map to store the visited vertical levels in descending order.
class Solution
{
public:
    // Function to return a vector containing the top view of the binary tree
    vector<int> topView(Node *root)
    {
        // If the root is NULL, return an empty vector
        if (root == NULL)
            return {};

        // Create a queue to hold pairs of Node pointers and their vertical distances from the root
        queue<pair<Node *, /*vertical*/ int>> Q;

        // Create a map to hold the first node at each vertical distance
        map</*vertical*/ int, Node *> mapp;

        // Push the root node into the queue with a vertical distance of 0
        Q.push({root, 0});

        // Add the root node to the map
        mapp[0] = root;

        // While there are nodes in the queue
        while (!Q.empty())
        {
            // Get the node at the front of the queue
            auto top = Q.front();

            // Get its vertical distance
            int vertical = top.second;

            // Remove it from the queue
            Q.pop();

            // If it has a left child
            if (top.first->left)
            {
                // Add the left child to the queue with a vertical distance one less than its parent's
                Q.push({top.first->left, vertical - 1});
                // If there is no node in the map at this vertical distance yet
                if (mapp.find(vertical - 1) == mapp.end())
                {
                    // Add this node to the map
                    mapp[vertical - 1] = top.first->left;
                }
            }
            // If it has a right child
            if (top.first->right)
            {
                // Add the right child to the queue with a vertical distance one more than its parent's
                Q.push({top.first->right, vertical + 1});
                // If there is no node in the map at this vertical distance yet
                if (mapp.find(vertical + 1) == mapp.end())
                {
                    // Add this node to the map
                    mapp[vertical + 1] = top.first->right;
                }
            }
        }

        // Create a vector to hold the answer
        vector<int> ans;

        // For each entry in the map (which are sorted by their keys, i.e., their vertical distances)
        for (auto node : mapp)
            // Add the data of the node to the answer vector
            ans.push_back(node.second->data);

        // Return the answer vector
        return ans;
    }
};