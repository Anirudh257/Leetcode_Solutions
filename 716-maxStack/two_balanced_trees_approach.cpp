// Time complexity:
// push, top, peekMax - O(1), pop, popMax - O(logN)
// Space complexity: O(N)
class MaxStack {
public:
    set<pair<int, int>> st;
    set<pair<int, int>> valOrd;
    int cnt;
    MaxStack() {
        cnt = 0;
    }
    
    void push(int x) {
        st.insert({cnt, x});
        valOrd.insert({x, cnt});
        cnt++;
    }
    
    int pop() {
        if (st.empty()) {
            return -1;
        }
        pair<int, int> p = *st.rbegin();
        st.erase(p);
        valOrd.erase({p.second, p.first});
        return p.second;
    }
    
    int top() {
        if (st.empty()) {
            return -1;
        }
        return st.rbegin()->second;
    }

    
    int peekMax() {
        if (st.empty()) {
            return -1;
        }
        return valOrd.rbegin()->first;
    }
    
    int popMax() {
        pair<int, int> p = *valOrd.rbegin();
        valOrd.erase(p);
        st.erase({p.second, p.first});
        return p.first;

    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
