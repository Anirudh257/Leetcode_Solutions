class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Time complexity: O(n x 2 x 3), Space complexity: O(n x 2 x 3) + Auxiliary Stack Space: O(n)
        int len = prices.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(2, vector<int>(3, -1)));
        return compProf(prices, 0, len, 2, 1, dp);
    }
private:
    int compProf(vector<int>& prices, int ind, int len, int cap, int buy, vector<vector<vector<int>>>& dp) {
        if (cap == 0) {
            return 0;
        }
        if (ind == len) {
            return 0;
        }
        
        if (dp[ind][buy][cap] != -1) {
            return dp[ind][buy][cap];
        }
        
        int prof = 0;
        
        if (buy) {
            prof = max(-prices[ind] + compProf(prices, ind + 1, len, cap, 0, dp), compProf(prices, ind + 1, len, cap, 1, dp));
        }
        else {
            prof = max(prices[ind] + compProf(prices, ind + 1, len, cap - 1, 1, dp), compProf(prices, ind + 1, len, cap, 0, dp));
        }
        
        return dp[ind][buy][cap] = prof;
    }
};