// Time complexity: push - O(logN), pop - O(logN), top - O(1), peekMax - O(logN), 
// popMax - O(1)
// Space complexity: O(N)
class MaxStack {
public:
    stack<pair<int, int>> st;
    unordered_set<int> remInd;
    priority_queue<pair<int, int>> pq;
    int cnt;
    MaxStack() {
        cnt = 0;
    }
    
    void push(int x) {
        st.push({x, cnt});
        pq.push({x, cnt});
        cnt++;
    }
    
    int pop() {
        while (remInd.count(st.top().second)) {
            st.pop();
        }
        const pair<int, int> top = st.top();
        st.pop();
        remInd.insert(top.second);
        return top.first;
    }
    
    int top() {
        while (remInd.count(st.top().second)) {
            st.pop();
        }
        const pair<int, int> top = st.top();
        return top.first;
    }
    
    int peekMax() {
        while (remInd.count(pq.top().second)) {
            pq.pop();
        }     
        return pq.top().first;   
    }
    
    int popMax() {
        while (remInd.count(pq.top().second)) {
            pq.pop();
        }
        const pair<int, int> top = pq.top();
        pq.pop();
        remInd.insert(top.second);
        return top.first;

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
