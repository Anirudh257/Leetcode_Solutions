// Time complexity: O(N), Space complexity: O(N)
// Stack class.
class Stack {
    
public:
    int* arr;
    int size;
    int topInd;
    
    Stack(int capacity) {
        size = capacity;
        arr = new int[size];
        topInd = -1;
    }

    void push(int num) {
        if (topInd == size - 1) {
            return;
        }
        
        else if (topInd == -1) {
            topInd = 0;
            arr[topInd] = num;
        }
        else {
            topInd++;
            arr[topInd] = num;
        }
    }

    int pop() {
        if (topInd >= 0) {
            int topElem = arr[topInd];
            topInd--;
            return topElem;
        }
        else {
            return -1;
        }
    }
    
    int top() {
        if (topInd >= 0) {
            int topElem = arr[topInd];
            return topElem;
        }
        else {
            return -1;
        }
    }
    
    int isEmpty() {
        return topInd == -1;
    }
    
    int isFull() {
        return topInd == size - 1;
    }
    
};
