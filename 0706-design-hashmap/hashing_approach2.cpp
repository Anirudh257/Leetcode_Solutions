// Time complexity: O(1), Space complexity: O(N)
class MyHashMap {
    vector<list<pair<int, int>>> myMap;
    size_t size = 10000;
public:
    MyHashMap() {
        myMap.resize(size);
    }
    
    void put(int key, int value) {
        auto& list = myMap[key % size];
        for (auto& val : list) {
            if (val.first == key) {
                val.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }
    
    int get(int key) {
        auto& list = myMap[key % size];
        if (list.empty()) {
            return -1;
        }
        for (const auto& val : list) {
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        auto& list = myMap[key % size];
        list.remove_if([key] (auto n) {return n.first == key; });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
