// Time complexity: O(N), Space complexity: O(N)
class MyHashSet {
vector<list<int>> mySet;
int size;

public:
        
    MyHashSet() {
        size = 100;
        mySet.resize(size);
    }

    int hash(int key) {
        return (key % size);
    }

    list<int>:: iterator search(int key) {
        int h = hash(key);

        return find(mySet[h].begin(), mySet[h].end(), key);
    }
    
    void add(int key) {
        if (contains(key)) {
            return;
        }

        int h = hash(key);

        mySet[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);

        if (!contains(key)) {
            return;
        }

        mySet[h].erase(search(key));
    }
    
    bool contains(int key) {
        int h = hash(key);

        if (search(key) != mySet[h].end()) {
            return true;
        }     

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
