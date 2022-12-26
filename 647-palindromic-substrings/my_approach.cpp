// Time complexity: O(n^2), Space complexity: O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int numSubs = 0;
        
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
        }

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (i == j) {
                    numSubs += 1;
                }
                else if (i == j  - 1){
                    if (s[i] == s[j]) {
                        dp[i][j] = 2;
                        numSubs += 1;
                    }
                }
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == j - i - 1) {
                        dp[i][j] = j - i + 1;
                        numSubs += 1;
                    }
                }
            }
        }

        return numSubs;
    }
};
