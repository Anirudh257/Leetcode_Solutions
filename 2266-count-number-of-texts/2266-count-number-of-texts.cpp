class Solution {
public:
    int countTexts(string pressedKeys) {
        // Time complexity: O(N), Space complexity: O(N)
        int n = pressedKeys.length();
        vector<int> dp(n + 1, -1);
        
        // Time complexity: O
        
        return countPoss(pressedKeys, dp, 0, n);
    }
private:
    int mod = 1e9 + 7;
    int countPoss(string& s, vector<int>& dp, int ind, int n) { 
        if (ind >= n) {
            return 1;
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }
        
        int ans = 0;
        
        // decode 2 characters at a time: (22)/(23)
        if (ind + 1 < n && s[ind] == s[ind + 1]) {
            ans += countPoss(s, dp, ind + 2, n);
            ans %= mod;
            
            // decode 3 characters at a time: (223)/(222)
            if (ind + 2 < n && s[ind] == s[ind + 2]) {
                ans += countPoss(s, dp, ind + 3, n);
                ans%=mod;
                
                // decode 4 characters at a time: (2222)/(2223)
                if ((ind + 3 < n && s[ind] == s[ind + 3]) && (s[ind] == '7' || s[ind] == '9')) {
                    ans += countPoss(s, dp, ind + 4, n);
                    ans%= mod;
                } 
            }
        }
        
        // decode 1 character at a time: (2)/(3)
        ans += countPoss(s, dp, ind + 1, n);
        ans%=mod;
        
        return dp[ind] = ans;
    }
};