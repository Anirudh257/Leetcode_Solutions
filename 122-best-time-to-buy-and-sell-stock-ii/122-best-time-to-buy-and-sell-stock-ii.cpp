class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        // Time complexity: O(nx2), Space complexity: O(nx2) + Auxiliary Stack Space O(N)
        vector<vector<int>> dp(len, vector<int>(2, -1));
        
        return compProf(prices, 0, len, dp,  true);   
    }
private:
    // Time complexity: O(2^n), Space complexity: O(n)
    int compProf(vector<int>& prices, int ind, int len, vector<vector<int>>& dp, bool buy) {
        if (ind == len) {
            return 0;
        }   
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        int profit = 0;
        
        if (buy) {
            dp[ind][buy] = max(-prices[ind] + compProf(prices, ind + 1, len, dp, false), compProf(prices, ind + 1, len, dp, true));
        }
        else {
            dp[ind][buy] = max(prices[ind] + compProf(prices, ind + 1, len, dp, true), compProf(prices, ind + 1, len, dp, false));    
        }
        
        return dp[ind][buy];
    }
};