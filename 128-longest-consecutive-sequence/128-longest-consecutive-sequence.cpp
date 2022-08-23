class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       // Time complexity: O(N), Space complexity: O(N)
        unordered_set<int> hashSet;
        
        for (int n : nums) {
            hashSet.insert(n);
        }
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