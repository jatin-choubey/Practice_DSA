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

The Idea here is to map every vertical level with its first found node, because the inital encountered node at
any vertical level will be the only one visible from the top.

We utilize a 'map' data structure for this purpose because it allows us to print the nodes
from left to right, ensuring that nodes with the smallest vertical positions are printed first.

*/

// Approach :
// Using the Level Order Traversal and Ordered Map to store the visited vertical levels in descending order.
class Solution
{
public:
    vector<int> topView(Node *root)
    {
        // Check if the root is NULL (empty tree).
        if (root == NULL)
            return {}; // Return an empty vector if the tree is empty.

        // Create a queue to perform level-order traversal of the tree.
        queue<pair<Node *, int>> Q;

        // Create a map to store the vertical distance as the key and the first node encountered at that distance as the value.
        map<int, Node *> mapp;

        // Start with the root node at a vertical distance of 0.
        Q.push({root, 0});

        // Initialize the map with the root node at distance 0.
        mapp[0] = root;

        while (!Q.empty())
        {
            int size = Q.size();

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++)
            {
                auto top = Q.front();

                int vertical = top.second;

                Q.pop();

                // Explore the left child and enqueue it with a decreased vertical distance.
                if (top.first->left)
                {
                    Q.push({top.first->left, vertical - 1});

                    // If the vertical distance is not in the map, add the left child as the first node at that distance.
                    if (mapp.find(vertical - 1) == mapp.end())
                    {
                        mapp[vertical - 1] = top.first->left;
                    }
                }

                // Explore the right child and enqueue it with an increased vertical distance.
                if (top.first->right)
                {
                    Q.push({top.first->right, vertical + 1});

                    // If the vertical distance is not in the map, add the right child as the first node at that distance.
                    if (mapp.find(vertical + 1) == mapp.end())
                    {
                        mapp[vertical + 1] = top.first->right;
                    }
                }
            }
        }

        // Create a vector to store the top view nodes.
        vector<int> ans;

        // Iterate through the map and add the data of the first nodes to the answer vector.
        for (auto node : mapp)
            ans.push_back(node.second->data);

        return ans; // Return the vector containing the top view nodes.
    }
};
