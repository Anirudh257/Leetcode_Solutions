// Time complexity: O(n^3), Space complexity: O(N) + Auxiliary Space of O(N)
// n^2 ways to break the string * n to create the substring every time.
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashSet;

        for (string s : wordDict) {
            hashSet.insert(s);
        }
        // memo[i] = s[i, .., end] can be divided/not divided.
        unordered_map<int, bool> memo;

        return wordBreak(s, hashSet, memo, 0);
    }
private:
    bool wordBreak(string s, unordered_set<string>& hashSet, unordered_map<int, bool>& memo,int pos) {
        if (pos >= s.size()) {
            return true;
        }
        if (memo.count(pos)) {
            return memo[pos];
        }
        string t = "";
        for (int i = pos; i < s.size(); i++) {
            if (hashSet.count(s.substr(pos, i - pos + 1)) && wordBreak(s, hashSet, memo, i + 1)) {
                return memo[pos] = true;
            }
        }
        return memo[pos] = false;
    }
};
