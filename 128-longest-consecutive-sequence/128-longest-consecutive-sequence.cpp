class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        
        for (int n : nums) {
            hashSet.insert(n);
        }
        
        // Time complexity: O(n), Space complexity: O(n)
        int longStreak = 0;
        
        for (int n : nums) {
            if (!hashSet.count(n - 1)) {
                int currStreak = 1;
                
                while(hashSet.count(n + 1)) {
                    currStreak++;
                    n++;
                }
                longStreak = max(longStreak, currStreak);
            }
        }
        
        return longStreak;
    }
};