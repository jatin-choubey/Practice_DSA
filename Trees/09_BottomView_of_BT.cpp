/*
hat will the tree look like, when viewed from Bottom
(Left to Right)


        0
      /  \
     1    2
   /  \    \
  3    4    5
      / \
     6   7

       ^
      ||
eyes looking from Bottom

output : 3, 6, 4, 7, 5


The Idea here is to map every node with its vertical level.
It maintains the most recent node for each vertical position.

We utilize a 'map' data structure for this purpose because it allows us to print the nodes
from left to right, ensuring that nodes with the smallest vertical positions are printed first.

*/

cclass Solution
{
public:
    vector<int> bottomView(Node * root)
    {
        // Check if the root is NULL (empty tree).
        if (root == NULL)
            return {}; // Return an empty vector if the tree is empty.

        // Create a map to store the horizontal distance as the key and the last node at that distance as the value.
        map<int, Node *> mapp;

        // Create a queue to perform level-order traversal of the tree.
        queue<pair<int, Node *>> Q;

        // Start with the root node at a horizontal distance of 0.
        Q.push({0, root});

        // Initialize the map with the root node at distance 0.
        mapp[0] = root;

        while (!Q.empty())
        {
            int size = Q.size();

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++)
            {
                auto top = Q.front();

                int vertical = top.first;
                Node *node = top.second;
                Q.pop();

                // Explore the left child and enqueue it with a decreased horizontal distance.
                if (node->left)
                {
                    mapp[vertical - 1] = node->left;
                    Q.push({vertical - 1, node->left});
                }

                // Explore the right child and enqueue it with an increased horizontal distance.
                if (node->right)
                {
                    mapp[vertical + 1] = node->right;
                    Q.push({vertical + 1, node->right});
                }
            }
        }

        // Create a vector to store the bottom view nodes.
        vector<int> ans;

        // Iterate through the map and add the data of the last nodes to the answer vector.
        for (auto node : mapp)
            ans.push_back(node.second->data);

        return ans; // Return the vector containing the bottom view nodes.
    }
}
