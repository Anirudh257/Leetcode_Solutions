class MedianFinder {
public:
    MedianFinder() {
        
    }
    // Time complexity: O(nlogn), Space complexity: O(n)
    void addNum(int num) {
        firHalf.push(num);

        // Ensure all elements in firHalf <= secHalf
        if (!firHalf.empty() && !secHalf.empty() && firHalf.top() > secHalf.top()) {
            int firTop = firHalf.top();
            firHalf.pop();
            secHalf.push(firTop);
        }

        // Ensure balance, len(firHalf) == len(secHalf) + 1  
        if (firHalf.size() > secHalf.size() + 1) {
            int firTop = firHalf.top();
            firHalf.pop();
            secHalf.push(firTop);
        }
        
        // Ensure balance, len(secHalf) == len(firHalf) + 1
        if (secHalf.size() > firHalf.size() + 1) {
            int secTop = secHalf.top();
            secHalf.pop();
            firHalf.push(secTop);
        }

    }
    
    double findMedian() {
        // If odd length, return the top element of either firHalf/secHalf
        if (firHalf.size() > secHalf.size()) {
            return firHalf.top();
        }   

        if (secHalf.size() > firHalf.size()) {
            return secHalf.top();
        }

        return (firHalf.top() + secHalf.top())/2.0;
    }
private:
    priority_queue<int> firHalf; //MaxHeap
    priority_queue<int, vector<int>, greater<int>> secHalf; //MinHeap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */