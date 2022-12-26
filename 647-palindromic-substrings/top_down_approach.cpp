// Time complexity: O(n^2), Space complexity: O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        if (len == 1) {
            return 1;
        }
        int numSubs = 0;
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
            numSubs += 1;
        }

        for (int i = 0; i < len - 1; i++) {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            numSubs += dp[i][i + 1];
        }

        for (int n = 3; n <= len; n++) {
            for (int i = 0, j = i + n - 1; j < len; i++,j++) {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                numSubs += dp[i][j]; 
            }
        }

        return numSubs;
    }
};
