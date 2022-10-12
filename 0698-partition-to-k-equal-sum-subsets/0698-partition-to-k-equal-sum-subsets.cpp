class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        // Time complexity: O(k.2^N), Space complexity: O(N) auxiliary stack space.
        int size = nums.size();
        int totSum = 0;
        
        for (auto &x : nums) {
            totSum += x;
        }
        if (totSum % k != 0) {
            return false;
        }
        
        string taken(size, '0');
        
//         vector<bool> visited(size, false);
        
        unordered_map<string, bool> memo;
        sort(nums.begin(), nums.end(), comp);
        
    
        return canPartition(nums, k, 0,  0, 0, totSum/k, taken, memo);
    }
private:
    static bool comp(int a, int b) {
        return a > b;
    }
    
    bool canPartition(vector<int>& nums, int k, int ind, int currSum, int numSubs, int targetSum, string& taken, unordered_map<string, bool>& memo) {
        // k - 1 subsets found and last subset will have the same sum as well.
        if (numSubs == k - 1) {
            return true;
        }
        
        // If current Sum > required sum, just return false as getting the subset is impossible.
        if (currSum > targetSum) {
            return false;
        }
        
        // If the combination of subsets has been taken already
        if (memo.find(taken) != memo.end()) {
            return memo[taken];
        }
        
        
        // If the subset sum == target sum, we can start again to search for other subsets (neglecting the already chosen ones)
        if (currSum == targetSum) {
            return memo[taken] =  canPartition(nums, k, 0, 0, numSubs + 1, targetSum, taken, memo);
        }
        
        for (int i = ind; i < nums.size(); i++) {
            
            // If not explored already
            if (taken[i] == '0') {
                taken[i] = '1';
                
                // Explore path of taking the current element nums[i] in the subset
                if (canPartition(nums, k, i + 1, currSum + nums[i], numSubs, targetSum, taken, memo)) {
                    return true;
                }
                
                // remove from the subset as it hasn't lead to the result
                taken[i] = '0';
            }
            
        }
        return false;
    }
};