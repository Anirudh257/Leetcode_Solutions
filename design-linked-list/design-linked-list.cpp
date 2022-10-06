class MyLinkedList {
vector<int> llist;

public:
    MyLinkedList() {
        // int val;
        // MyLinkedList* next;
    }
    

    
    int get(int index) {
        if (index >= llist.size()) {
            return -1;
        }
        

        return llist[index];
    }
    
    void addAtHead(int val) {
        // for (auto &x: llist) {
        //     cout << x << endl;
        // }
        
        if (llist.size() == 0) {
            llist.push_back(val);
        }
        else {
            llist.insert(llist.begin(), val);         
        }
        // cout << "Here " << endl;
        
    }
    
    void addAtTail(int val) {
        
        
        llist.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > llist.size()) {
            return;
        }
        
        llist.insert(llist.begin() + index, val);
    }
    
    void deleteAtIndex(int index) {
        if (index >= llist.size()) {
            return;
        }
        llist.erase(llist.begin() + index);
    }
    

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */