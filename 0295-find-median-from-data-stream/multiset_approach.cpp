class MedianFinder {
public:
    MedianFinder() {
        loMedian = data.end();
        hiMedian = data.end();
    }
    // Time complexity: O(nlogn), Space complexity: O(N)
    
    void addNum(int num) {
        data.insert(num);
        
        int size = data.size();
        
        if (size == 1) {
            loMedian = hiMedian = data.begin();
        }
        // Odd number of elements
        else if (size & 1) {
            if (num > *loMedian && num < *hiMedian) {
                loMedian++;
                hiMedian--;
            }
            else if (num >= *hiMedian) {
                loMedian++;
            }
            else {
                loMedian = --hiMedian;
                
            }
            
        }
        // Even number of elements
        else {
            if (num < *loMedian) {
                loMedian--;
            }
            else {
                hiMedian++;
            }
        }
        
        
    }
    
    double findMedian() {
        return (double)((*loMedian + *hiMedian)/2.0);
    }
private:
    multiset<int> data;
    multiset<int>::iterator loMedian, hiMedian;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
