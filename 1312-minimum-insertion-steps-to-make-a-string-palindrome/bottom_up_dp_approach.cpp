// Time complexity: O(n^2), Space complexity: O(n^2) 
class Solution {
public:
    int minInsertions(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                int numInsert = 0;
                if (s[i] == s[j]) {
                    numInsert = dp[i + 1][j - 1];
                }
                else {
                    numInsert = 1   + min(dp[i + 1][j], dp[i][j - 1]);
                }
                dp[i][j] = numInsert;
            }
        }

        return dp[0][len - 1];
    }
};