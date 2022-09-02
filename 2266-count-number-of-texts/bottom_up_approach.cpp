class Solution {
public:
    int countTexts(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        // Bottom up approach 
        // Time complexity: O(N), Space complexity: O(N)
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            
            if (i > 0 && s[i] == s[i - 1]) {
                dp[i + 1] = (dp[i + 1] + dp[i - 1])%mod;
 
                if (i > 1 && s[i] == s[i - 2]) {
                    dp[i + 1] = (dp[i + 1] + dp[i - 2])%mod;
                    
                    if (i > 2 && s[i] == s[i - 3] && (s[i] == '9' || s[i] == '7')) {
                        dp[i + 1] = (dp[i + 1] + dp[i - 3])%mod;
                    }
                }
            }     
        }
        
        
        return dp[n];
    }
};
