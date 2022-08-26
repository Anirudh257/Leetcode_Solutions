class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len + 1);
        
        dp[0] = 1; // Only 1 way to decode empty string
        
        dp[1] = s[0] == '0' ? 0 : 1; // If not 0, number of ways = 1 to decode 1 number.
        
        for (int i = 2; i < dp.size(); i++) {
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }
            
            int twoDig = stoi(s.substr(i - 2, 2));
            
            if (twoDig >= 10 && twoDig <= 26) {
                dp[i] += dp[i - 2];
            }
            
        }
        
        
        return dp[len];
    }
};
