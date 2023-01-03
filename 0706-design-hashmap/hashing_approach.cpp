// Time complexity: O(1), Space complexity: O(Number of calls)
struct Node {
public:
    int key, val;
    Node* next;
    Node(int k, int v, Node* n) {
        key = k;
        val = v;
        next = n;
    }
};

class MyHashMap {
public:
    const static int size = 19997;
    const static int mul = 12582917;
    Node* data[size] = {};

    int hash(int key) {
        return (int) ((long)key*mul%size);
    }

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, value, data[h]);
        data[h] = node;
    }
    
    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        for (; node != NULL; node = node->next) {
            if (node->key == key) {
                return node->val;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (!node) {
            return;
        }
        if (node->key == key) {
            data[h] = node->next;
            delete node;
        }
        else {
            for (; node->next != NULL; node = node->next) {
                if (node->next->key == key) {
                    Node* temp = node->next;
                    node->next = temp->next;
                    delete temp;
                    return;
                }
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
