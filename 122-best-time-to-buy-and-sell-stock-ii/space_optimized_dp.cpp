class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        // Tabulation approach
        // Time complexity: O(nx2), Space complexity: O(2) 
        // vector<vector<int>> dp(len + 1, vector<int>(2, 0));
        vector<int> ahead(2, 0), curr (2, 0);
        
        ahead[0] = ahead[1] = 0;
        
        for (int ind = len - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if (buy) {
                    profit = max(-prices[ind] + ahead[0], ahead[1]);
                }
                else {
                    profit = max(prices[ind] + ahead[1], ahead[0]);    
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        
        
        return ahead[1];   
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
