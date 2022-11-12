class MedianFinder {
public:
    MedianFinder() {
        // Time complexity: O(nlogn), 1 element insertion takes logn time in a binary heap and for n elements, nlogn
        // Space complexity: O(N) for maintaining heaps
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        
        minHeap.push(maxHeap.top()); // Add element to lower half
        
        maxHeap.pop(); 
        
        // Balance tree ensuring that maxHeap.size == minHeap.size() always
        
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            med = maxHeap.top();
        }
        else {
            med = (double)(maxHeap.top() + minHeap.top())/2;
        }
        return med;
    }
private:
    priority_queue<int> maxHeap; // First half sorted in the ascending order and top of 1st half
    priority_queue<int, vector<int>, greater<int>> minHeap; // 2nd half in ascending order and get top of 2nd half.
    double med;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */