class Solution {
public:
    // Time complexity: O(N*T), N = number of coins, T = amount
    // Space complexity: O(N*T) + Auxiliary space of O(T)
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int res = compCoins(coins, amount, coins.size() - 1, dp);
        if (res != 1e9) {
            return res;
        }
        return -1;
    }
private:
    int compCoins(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (amount % coins[ind] == 0) {
                return dp[ind][amount] = amount/coins[ind];
            }
            else {
                return 1e9;
            }
        }
        
        if (ind < 0) {
            return 0;
        }
        if (dp[ind][amount] != -1) {
            return dp[ind][amount];
        }
        
        int take = 1e9;
        int notTake = compCoins(coins, amount, ind - 1, dp);
        
        if (coins[ind] <= amount) {
            take = 1 + compCoins(coins, amount - coins[ind], ind, dp);
        }
        
        return dp[ind][amount] =  min(take, notTake);
    }
};
