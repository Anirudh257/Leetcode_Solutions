// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        } 
        int len = s.size();
        vector<long long int> dp(len + 1, 0);
        dp[0] = 1;

        dp[1] = s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1;

        for (int i = 1; i < len; i++) {
            if (s[i] == '*') {
                dp[i + 1] = (9*dp[i]) % MOD;
                if (s[i - 1] == '1') {
                    dp[i + 1] = (dp[i + 1] + 9*dp[i - 1]) % MOD;
                }
                else if (s[i - 1] == '2') {
                    dp[i + 1] = (dp[i + 1] + 6*dp[i - 1]) % MOD;
                }
                else if (s[i - 1] == '*') {
                    dp[i + 1] = (dp[i + 1] + 15*dp[i - 1]) % MOD;
                }
            }
            else {
                dp[i + 1] = s[i] != '0' ? dp[i] : 0;
                if (s[i - 1] == '1') {
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
                }
                else if (s[i - 1] == '2' && s[i] <= '6') {
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
                }
                else if (s[i - 1] == '*') {
                    dp[i + 1] = (dp[i + 1] + (s[i] <= '6' ? 2 : 1)* dp[i - 1]) % MOD;
                }
            }
            
        }

        return int(dp[len]);
    }
private:
    int MOD = int(pow(10, 9) + 7);
};
