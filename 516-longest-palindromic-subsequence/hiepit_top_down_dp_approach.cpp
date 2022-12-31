// Time complexity: O(N^2), Space complexity: O(N^2) + Auxiliary stack space O(N)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1000][1000] = {};
        return compRec(dp, s, 0, s.size() - 1);
    }
private:
    int compRec(int dp[1000][1000], string& s, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return 1;
        }
        if (dp[l][r] != 0) {
            return dp[l][r];
        }
        if (s[l] == s[r]) {
            dp[l][r] = 2 + compRec(dp, s, l + 1, r - 1);
        }
        else {
            dp[l][r] = max(compRec(dp, s, l + 1, r), compRec(dp, s, l, r - 1));
        }
        return dp[l][r];
    }
};
