class Solution {
public:
    // Time complexity: O(n*2^n), Space complexity: O(2^n)
    int subsetXORSum(vector<int>& nums) {
        // int reqSum = 0;
        
        vector<vector<int>> subs;
        
        compSubs(nums, 0, 0);
                
        return reqSum;
    }
private:
    int reqSum = 0;
    void compSubs(vector<int>& nums, int ind, int currSum) {
        if (ind == nums.size()) {
            reqSum += currSum;
            return;
        }
        
        compSubs(nums, ind + 1, currSum);
        compSubs(nums, ind + 1, currSum ^= nums[ind]);
        
        return;
    }
};
