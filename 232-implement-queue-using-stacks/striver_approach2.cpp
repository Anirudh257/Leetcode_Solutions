//Time complexity: push, empty - O(1), pop, peek - O(N)
// Space complexity: O(N)
class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {
        if (!input.empty()) {
            input.pop();
        }
        if (!output.empty()) {
            output.pop();
        }
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int top = output.top();
        output.pop();
        return top;
    }
    
    int peek() {
        if (output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int top = output.top();
        return top;    
    }
    
    bool empty() {
        return output.empty() && input.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
