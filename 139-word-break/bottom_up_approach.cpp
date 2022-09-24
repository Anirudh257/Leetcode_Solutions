class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        // Time complexity: O(n^3): n^2 for loop + n for substring formation, Space complexity: O(n) 
        unordered_set<string> hashSet;
        for (auto &x : wordDict) {
            hashSet.insert(x);
        }
        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = true;
        dp[s.size() - 1] = true ? hashSet.count(s.substr(s.size() - 1, 1)) : false;
        
        for (int pos = s.size() - 2; pos >= 0; pos--) {
            for (int i = pos; i < s.size(); i++) {
                if (hashSet.count(s.substr(pos, i - pos + 1)) && dp[i + 1]) {
                    dp[pos] = true;
                }
            }
        }
        
        return dp[0];
    }
private:
    bool perfWordBreak(string s, unordered_set<string>& hashSet, int pos, vector<int>& dp) {
        if (pos == s.size()) {
            return true;
        }
        if (dp[pos] != 2) {
            return dp[pos];
        }
        
        for (int i = pos; i < s.size(); i++) {
            if (hashSet.count(s.substr(pos, i - pos + 1)) && perfWordBreak(s, hashSet, i + 1, dp)) {
                return dp[pos] = true;
            }
        }
        return dp[pos] = false;
    }
};
