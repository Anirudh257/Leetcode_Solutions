// Time complexity: O(n^3), Space complexity: O(N^2)
// n^2 ways to break the string * n to create the substring every time.
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashSet;

        for (string s : wordDict) {
            hashSet.insert(s);
        }
        int size = s.length();

        bool dp[size + 1][size + 1];

        for (int len = 1; len <= size; len++) {
            int start = 1;
            int end = len;

            while(end <= size) {
                string sub = s.substr(start - 1,len);

                if (hashSet.count(sub))  {
                    dp[start][end] = true;
                }
                else {
                    // O(N) check if substrings [0, 2][2, N], [0, 3][4, N],... are possible
                    bool flag = false;
                    for (int i = start; i < end; i++) {
                        if (dp[start][i] && dp[i + 1][end]) {
                            flag = true;
                            break;
                        }
                    }
                    dp[start][end] = flag;
                }
                start += 1;
                end += 1;
            }

        }

        return dp[1][size];

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
