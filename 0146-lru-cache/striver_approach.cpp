// Time complexity: O(1)
// Space complexity: O(N)
class LRUCache {
public:
    // Doubly linked list to store ([key, val] pairs)
    // Inserting new ([key, val]) after head so that the
    // the least recently used element is before the tail node.
    class node {
        public:
            int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // Dummy head and tail nodes to quickly refer to the lru_nodes.
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    unordered_map<int, node*> m;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;    
    }
    
    int get(int key) {
        // If key exists in the map
        // Delete from list and update position after the head node
        if (m.find(key) != m.end()) {
            node* currNode = m[key];
            int val = currNode->val;
            m.erase(key);
            deleteNode(currNode);
            addNode(currNode);
            m[key] = head->next;
            return val;
        }
        // If key not in map
        return -1;
    }

    void addNode(node* newNode) {
        node* temp = head->next;
        temp->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
    }

    void deleteNode(node* nodeToDel) {
        node* nodePrev = nodeToDel->prev;
        node* nodeNext = nodeToDel->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }
    
    void put(int key, int value) {
        // Before putting check if the key already exists in the map
        // If yes, delete the existing (key, value) pair and update the map.
        if (m.find(key) != m.end()) {
            node* currNode = m[key];
            m.erase(key);
            deleteNode(currNode);
        }

        // Check if cache has reached capacity and delete the lru_key
        // Since new nodes/updating nodes are inserted after head, the 
        // lru_key ends up before the tail node.
        if (m.size() == cap) {
            node* lruNode = tail->prev;
            int lruKey = lruNode->key;
            m.erase(lruKey);
            deleteNode(lruNode);
        }
        // Else, just add the (key, val) pair to the map
        addNode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value); 
 */