class Solution {
public:
    // Time complexity: O(2^n*n), Space complexity: O(1)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        int size = nums.size();
        int numSubs = (1 << size); // 2^size
        
        for (int num = 0; num < numSubs; num++) {
            vector<int> sub;
            for (int j = 0; j < size; j++) {
                // pick based on index. Check if jth bit is set or not.
                if (num & (1 << j)) {
                    sub.push_back(nums[j]);
                }
            }
            subs.push_back(sub);
        }
        
        
        return subs;
    }
};