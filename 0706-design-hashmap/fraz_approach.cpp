// Time complexity: O(N), Space complexity: O(N)
class MyHashMap {
public:
    vector<list<pair<int, int>>> myMap;
    int size;
    MyHashMap() {
        size = 1000;
        myMap.resize(size);        
    }

    int hash(int key) {
        return key%size;
    }

    list<pair<int, int>>:: iterator search(int key) {
        int hashInd = hash(key);

        list<pair<int, int>>:: iterator it = myMap[hashInd].begin();

        while(it != myMap[hashInd].end()) {
            if (it->first == key) {
                return it;
            }
            it++;
        }

        return it;
    }
    
    void put(int key, int value) {
        remove(key);
        int hashInd = hash(key);
        myMap[hashInd].push_back({key, value});
    }
    
    int get(int key) {
        list<pair<int, int>>:: iterator it = search(key);
        int hashInd = hash(key);
        
        if (it == myMap[hashInd].end()) {
            return -1;
        }

        return it->second;
    }   
    
    void remove(int key) {
        int hashInd = hash(key);
        list<pair<int, int>>:: iterator it = search(key);

        if (it != myMap[hashInd].end()) {
            myMap[hashInd].erase(it);
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
