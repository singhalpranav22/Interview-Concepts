// 146. LRU Cache
// Medium

// 8553

// 347

// Add to List

// Share
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// Follow up:
// Could you do get and put in O(1) time complexity?

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 3000
// 0 <= value <= 104
// At most 3 * 104 calls will be made to get and put.

// LRU implemented using linked list with address of nodes in a hash table for fast access.
// Implementation seems messy due to care for NULL nodes.
struct node
{
    int val;
    int key;
    node *next = NULL;
    node *prev = NULL;
};
unordered_map<int, node *> mp;
class LRUCache
{
public:
    int cap = 0;
    int currLen = 0;
    node *head = NULL, *tail = NULL;
    LRUCache(int capacity)
    {
        mp.clear(); // clearing the grabage of the previous object from memory
        if (head != NULL)
        {
            node *temp = head;
            while (temp != NULL)
            {
                node *tp = temp;
                temp = temp->next;
                delete (tp);
            }
        }
        head = NULL, tail = NULL;
        cap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        int num = mp[key]->val;
        node *lf = mp[key]->prev, *rt = mp[key]->next;
        if (tail == mp[key])
            return num;
        if (head == mp[key])
        {
            head = rt;
            rt->prev = NULL;
        }
        if (lf != NULL)
            lf->next = rt;
        if (rt != NULL)
            rt->prev = lf;
        node *tpp = tail;
        tail->next = mp[key];
        tail = mp[key];
        tail->prev = tpp;
        return num;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            mp[key]->val = value;
            node *lf = mp[key]->prev, *rt = mp[key]->next;
            if (tail == mp[key])
                return;
            if (head == mp[key])
            {
                head = rt;
                rt->prev = NULL;
            }
            if (lf != NULL)
                lf->next = rt;
            if (rt != NULL)
                rt->prev = lf;
            node *tpp = tail;
            tail->next = mp[key];
            tail = mp[key];
            tail->prev = tpp;
            return;
        }
        else if (currLen < cap)
        {
            node *n = new node;
            n->val = value;
            n->key = key;
            mp[key] = n;
            if (head == NULL && tail == NULL)
            {
                head = n, tail = n;
                currLen++;
                return;
            }
            node *tp = tail;
            tail->next = n;
            tail = n;
            tail->prev = tp;
            currLen++;
            // cout<<currLen<<endl;
            return;
        }
        else
        {
            if (cap == 1)
            {
                node *temp = head;
                int tpp = temp->key;
                delete (temp);
                mp.erase(tpp);
                node *n = new node;
                n->val = value;
                n->key = key;
                mp[key] = n;
                head = n, tail = n;
                return;
            }
            node *temp = head;
            int tpp = temp->key;
            head = head->next;
            head->prev = NULL;
            delete (temp);
            mp.erase(tpp);
            node *n = new node;
            n->val = value;
            n->key = key;
            mp[key] = n;
            node *tp = tail;
            tail->next = n;
            tail = n;
            tail->prev = tp;
            return;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
