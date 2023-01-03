// Time complexity: O(1), Space complexity: O(N)
class MyHashMap {
public:
    MyHashMap() {
        vec.resize(size, -1);
    }
    
    void put(int key, int value) {
        vec[key] = value;        
    }
    
    int get(int key) {
        return vec[key];
    }
    
    void remove(int key) {
        vec[key] = -1;
    }
private:
    int size = (int)pow(10, 6) + 1;
    vector<int> vec;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
