// Time complexity: O(NlogN), Space complexity: O(N)
class MedianFinder {
public:
    MedianFinder() {
        med = 0.0;
        size = 0;
    }

    void addNum(int num) {
        size++;
        if (size == 1) {
            med = num;
            secHalf.push(num);
        }
        else {
            if (firHalf.empty()) {
                if (num >= secHalf.top()) {
                    secHalf.push(num);
                    int top = secHalf.top();
                    secHalf.pop();
                    firHalf.push(top);
                }
                else {
                    firHalf.push(num);
                }
            }
            else {
                int firTop = firHalf.top(), secTop = secHalf.top();
                if (firHalf.size() == secHalf.size()) {
                    if (num >= firTop) {
                        secHalf.push(num);
                    }
                    else {
                        firHalf.push(num);
                        int top = firHalf.top();
                        firHalf.pop();
                        secHalf.push(top);
                    }
                }
                else {
                    if (num >= firTop) {
                        secHalf.push(num);
                        int top = secHalf.top();
                        secHalf.pop();
                        firHalf.push(top);

                    }
                    else {
                        firHalf.push(num);
                    }
                }
            }
            if (size % 2 == 0) {
                med = (firHalf.top() + secHalf.top())/2.0; 
            }
            else {
                med = (double)secHalf.top();
            }
        }
    }
    
    double findMedian() {

        return med;
    }
private:
    priority_queue<int> firHalf;
    priority_queue<int, vector<int>, greater<int>> secHalf;
    double med;
    int size;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */