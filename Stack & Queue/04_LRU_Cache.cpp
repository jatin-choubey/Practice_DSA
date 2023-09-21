/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[   [2],    [1, 1], [2, 2], [1], [3, 3],  [2],  [4, 4], [1],  [3],   [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
------------
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/

// Using Dounbly Linked List and Hash Map
class LRUCache
{
public:
    // Define the node structure with key, value and pointers to next and previous nodes
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int KEY, int VAL) : key(KEY), val(VAL), next(nullptr), prev(nullptr) {}
    };

    // Define the maximum size of the cache and a map to store key-node pairs
    int maxSize;
    unordered_map<int, node *> umap;

    // Initialize dummy head and tail nodes
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    // Constructor to initialize the cache with given capacity and link head and tail nodes
    LRUCache(int capacity)
    {
        maxSize = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Function to add a new node after the head node
    void addNode(node *newNode)
    {
        node *temp = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = temp;
        temp->prev = newNode;
    }

    // Function to remove a given node from the doubly linked list
    void deleteNode(node *delNode)
    {
        node *prevDel = delNode->prev;
        node *nextDel = delNode->next;
        prevDel->next = nextDel;
        nextDel->prev = prevDel;
    }

    // Function to get the value of a key from the cache
    int get(int _key)
    {
        if (umap.find(_key) != umap.end())
        {
            // If key is found in the map, remove the corresponding node from the list and add it back after the head node
            node *toBeDeleted = umap[_key];
            deleteNode(toBeDeleted);
            addNode(toBeDeleted);
            return toBeDeleted->val; // Return the value of the key
        }
        return -1; // Return -1 if key is not found in the map
    }

    // Function to insert or update a key-value pair in the cache
    void put(int _key, int value)
    {
        if (umap.find(_key) != umap.end())
        {
            // If key is already present in the map, remove the corresponding node from the list and delete it from the map
            node *toBeDeleted = umap[_key];
            deleteNode(toBeDeleted);
            umap.erase(_key);
            delete toBeDeleted;
        }
        else if (umap.size() == maxSize)
        {
            // If cache is full, remove the least recently used element from the list (node before tail) and delete it from the map
            node *toBeDeleted = tail->prev;
            deleteNode(toBeDeleted);
            umap.erase(toBeDeleted->key);
            delete toBeDeleted;
        }

        // Create a new node with given key-value pair and add it after the head node. Also add it to the map.
        node *newNode = new node(_key, value);
        addNode(newNode);
        umap[_key] = newNode;
    }
};
