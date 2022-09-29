class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int numOdd = 0, totSubs = 0, count = 0, j = 0, size = nums.size();
        
        // Time complexity: O(N), Space complexity: O(1)
        for (int i = 0; i < size; i++) {
            if (nums[i] & 1) {
                numOdd++;
                
                if (numOdd >= k) {
                    count = 1;
                    
                    while(!(nums[j++] & 1)) {
                        count++;
                    }
                    totSubs += count;
                }
            }
            else if (numOdd >= k) {
                totSubs += count;
            }
        }
        
        return totSubs;
    }
};