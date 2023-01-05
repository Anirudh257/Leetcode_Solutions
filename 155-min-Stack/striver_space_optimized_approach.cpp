// Time complexity: O(1), Space complexity: O(N)
class MinStack {
public:
    long long int minElem;
    stack<long long> minSt;
    MinStack() {
        minElem = INT_MAX;
        if (!minSt.empty()) {
            minSt.pop();
        }
    }
    
    void push(int val) {
        long long value = (long) val;
        if (minSt.empty()) {
            minSt.push(value);
            minElem = value;
        }
        else {
            if (val < minElem) {
                minSt.push(2*value*1LL - minElem);
                minElem = value;
            }
            else {
                minSt.push(value);
            }
        }
    }
    
    void pop() {
        if (minElem > minSt.top()) {
            minElem = 2*minElem - minSt.top();
            minSt.pop();
        }
        else {
            minSt.pop();
        }
    }
    
    int top() {
        if (minElem > minSt.top()) {
            return minElem;
        }
        else {
            return minSt.top();
        }
    }
    
    int getMin() {
        return minElem;
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
