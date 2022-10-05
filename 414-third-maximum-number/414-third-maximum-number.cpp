class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        bool maxElemFound = false, maxElem2Found = false, maxElem3Found = false;
        int maxElem = 0, maxElem2 = 0, maxElem3 = 0, size = nums.size();
        priority_queue<int> pq;
        
        for (int n : nums) {
            pq.push(n);
        }
        
        
        
        
        while(!pq.empty()) {
            int top = pq.top();
            if (!maxElemFound) {
                maxElem = top;
                maxElemFound = true;
            }
            else {
                if (maxElem == top) {
                    ;
                }
                else {
                    if (!maxElem2Found) {
                        maxElem2 = top;
                        maxElem2Found = true;
                    }
                    else {
                        if (maxElem2 == top) {
                            ;
                        }
                        else {
                            maxElem3 = top;
                            maxElem3Found = true;
                            return maxElem3;
                        }
                    }
                }
            }
                
            pq.pop();
        }
        
        if (!maxElem3Found) {
            return maxElem;
        }
        
        return maxElem3;
    }
};