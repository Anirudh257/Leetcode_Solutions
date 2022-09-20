class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Time complexity: O(n), Space complexity: O(n)
        int maxConsLen = 0;
        unordered_map<int, int> um;
        
        for (int n : nums) {
            um[n] = 1;
        }
        
        for (int num : nums) {
            if (um.count(num - 1)) {
                continue;
            }
            else {
                int currLen = 0;
                int curr = num;
                while(um.count(curr)) {
                    currLen++;
                    curr++;
                }
                maxConsLen = max(currLen, maxConsLen);
            }
        }
        
        return maxConsLen;
    }
};