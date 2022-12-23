// Time complexity: O(N), Space complexity: O(N) + Auxiliary Stack Space O(N)
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        
        int len = s.size();
        vector<long long int> dp(len, -1);

        return (int)perfWays(s, len - 1, dp);
    }
private:
    int MOD = int(pow(10, 9) + 7);

    long long int perfWays(string& s, int ind, vector<long long int>& dp) {
        if (ind <  0) {
            return 1;
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }

        if (s[ind] == '*') {
            long long int res = 9*perfWays(s, ind - 1, dp)%MOD;
            if (ind > 0 && s[ind - 1] == '1') {
                res = (res + 9*perfWays(s, ind - 2, dp)) % MOD;
            }
            else if (ind > 0 && s[ind - 1] == '2') {
                res = (res + 6*perfWays(s, ind - 2, dp)) % MOD;
            }
            else if (ind > 0 && s[ind - 1] == '*') {
                res = (res + 15*perfWays(s, ind - 2, dp))%MOD;
            }
            return dp[ind] = res;
        }
        else {
            long long int res = s[ind] != '0' ? perfWays(s, ind  - 1, dp) : 0;
            if (ind > 0 && s[ind - 1] == '1') {
                res = (res + perfWays(s, ind - 2, dp)) % MOD;
            }
            else if (ind > 0 && s[ind - 1] == '2' && s[ind] <= '6') {
                res = (res + perfWays(s, ind - 2, dp)) % MOD;
            }
            else if (ind > 0 && s[ind - 1] == '*') {
                res = (res + (s[ind] <= '6' ? 2 : 1)*perfWays(s, ind - 2, dp)) % MOD;
            }
            return dp[ind] = res;

        }
    }
};
