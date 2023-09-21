/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently
used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3


*/

struct Node
{
    int key, value, cnt; // Node stores key, value, and frequency count.
    Node *next;          // Pointer to the next node.
    Node *prev;          // Pointer to the previous node.
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1; // Initialize count to 1 for a new node.
    }
};

struct List
{
    int size;
    Node *head; // Dummy head node.
    Node *tail; // Dummy tail node.
    List()
    {
        head = new Node(0, 0); // Initialize a dummy head node.
        tail = new Node(0, 0); // Initialize a dummy tail node.
        head->next = tail;     // Connect head to tail.
        tail->prev = head;     // Connect tail to head.
        size = 0;              // Initialize the size of the list to 0.
    }

    // Function to add a node to the front of the list.
    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; // Increment the size of the list when adding a node to the front.
    }

    // Function to remove a given node from the list.
    void removeNode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; // Decrement the size of the list when removing a node.
    }
};

class LFUCache
{
    map<int, Node *> keyNode;     // Map to store the key-node mapping.
    map<int, List *> freqListMap; // Map to store frequency-list mapping.
    int maxSizeCache;
    int minFreq; // Minimum frequency used to manage eviction.
    int curSize; // Current size of the cache.
public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0; // Initialize minimum frequency to 0.
        curSize = 0;
    }

    // Function to update frequency and move the node to the appropriate list.
    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key); // Remove the node from the key-node map.
        freqListMap[node->cnt]->removeNode(node);

        // If the current frequency becomes empty, update the minimum frequency.
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }

        // Find the next higher frequency list or create a new one.
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    // Function to get the value associated with a key.
    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    // Function to insert a key-value pair into the cache.
    void put(int key, int value)
    {
        if (maxSizeCache == 0)
        {
            return;
        }

        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if (curSize == maxSizeCache)
            {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1; // New value has to be added with a frequency of 1.
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};
