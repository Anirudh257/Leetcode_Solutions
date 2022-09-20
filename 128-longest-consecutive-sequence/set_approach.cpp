class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Time complexity: O(N), Space complexity: O(1)
        unordered_set<int> hSet(nums.begin(), nums.end());
        int maxLen = 0;
        
        for (int num : nums) {
            int curLen = 1;
            
            for (int i = 1; hSet.count(num - i); i++) {
                hSet.erase(num - i);
                curLen++;
            }
            for (int i = 1; hSet.count(num + i); i++) {
                hSet.erase(num + i);
                curLen++;
            }
            maxLen = max(maxLen, curLen);
        }
        
        return maxLen;
    }
};
