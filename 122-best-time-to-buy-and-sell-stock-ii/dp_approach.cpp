class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Time complexity: O(n x 2), Space complexity: O(n x 2) + Auxiliary Stack Space: O(N)
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, -1));
        return compProf(0, 1, prices, len, dp);
    }
private:
    int compProf(int ind, int buy, vector<int>& prices, int len, vector<vector<int>>& dp) {
        if (ind == len) {
            return 0;
        }
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        int profit = 0;
        if (buy) {
           profit = max(-prices[ind] + compProf(ind + 1, 0, prices, len, dp), compProf(ind + 1, 1, prices, len, dp));
        }
        else {
            profit = max(prices[ind] + compProf(ind + 1, 1, prices, len, dp), compProf(ind + 1, 0, prices, len, dp));
        }
        return dp[ind][buy] = profit;
    }
};
