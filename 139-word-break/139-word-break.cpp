class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashSet;
        for (auto &x : wordDict) {
            hashSet.insert(x);
        }
        vector<int> dp(s.size(), 2);
        return perfWordBreak(s, hashSet, 0, dp);
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