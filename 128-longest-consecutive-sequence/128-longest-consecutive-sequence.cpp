class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int res = 1;
        
        if (nums.size() == 0) {
            return 0;
        }
        
        for (int n : nums) {
            if (hashSet.find(n) == hashSet.end()) {
                continue;
            }
            hashSet.erase(n);
            int prev = n - 1;
            int next = n + 1;
            
            while(hashSet.find(prev) != hashSet.end()) {
                prev--;
            }
            
            while(hashSet.find(next) != hashSet.end()) {
                next++;
            }
            res = max(res, next - prev - 1);
            
        }
        
        return res;
    }
};