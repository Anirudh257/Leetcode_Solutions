// Time complexity: O(1), Space complexity: O(2N)
class MinStack {
public:
    stack<pair<int, int>> minSt;
    int minElem;
    MinStack() {
        // minElem = -1;
    }
    
    void push(int val) {
        if (minSt.size() == 0) {
            minElem = val;
        }
        else {
            minElem = min(val, minSt.top().second);
        }
        minSt.push({val, minElem});
    }
    
    void pop() {
        minSt.pop();
    }
    
    int top() {
        return minSt.top().first;
    }
    
    int getMin() {
        return minSt.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
