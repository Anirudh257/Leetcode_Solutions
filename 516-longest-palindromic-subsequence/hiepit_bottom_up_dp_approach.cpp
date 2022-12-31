// Time complexity: O(N^2), Space complexity: O(N^2) 
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1000][1000] = {};
        int len = s.length();

        for (int i = len - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][len - 1];
    }
};
