class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // Time complexity: O(N), Space complexity: O(N)
        vector<int> buckets(101);
        
        for (int h : heights) {
            buckets[h]++;
        }
        
        int hPtr = 1, nonMatch = 0;
        
        for (int h : heights) {
            while(buckets[hPtr] == 0) {
                hPtr++;
            }
            
            if (h != hPtr) {
                nonMatch++;
            }
            buckets[hPtr]--;
        }
        
        return nonMatch;
    }
};
