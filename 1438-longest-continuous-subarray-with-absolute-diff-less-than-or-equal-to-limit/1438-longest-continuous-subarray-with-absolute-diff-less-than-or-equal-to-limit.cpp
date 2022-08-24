class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int resLen = 0, n = nums.size(), i = 0, j;
        multiset<int> m;      
        
        // multiset does the dual job of keeping the minimum element at front (begin) and maximum element at end (rbegin), so, it is easier to get the
        // resulting length
        
        for (int j = 0; j < n; j++) {
            m.insert(nums[j]);
            if (*m.rbegin() - *m.begin() > limit) {
                m.erase(m.find(nums[i++]));
            }
            resLen =max(resLen, j - i + 1);
        }
        return resLen;
    }
};