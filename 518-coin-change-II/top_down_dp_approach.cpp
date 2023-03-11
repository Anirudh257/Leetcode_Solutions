// Time complexity: O(n*amount), Space complexity: O(n*amount) + Auxiliary Stack Space: O(amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<vector<int>> dp(size, vector<int>(amount + 1, -1));
        return compWays(coins, size - 1, amount, dp);
    }
private:
    int compWays(vector<int>& coins, int ind, int amount, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }
        if (ind < 0) {
            return 0;
        }

        if (dp[ind][amount] != -1) {
            return dp[ind][amount];
        }
        int take = 0;

        if (amount >= coins[ind]) {
            take = compWays(coins, ind, amount - coins[ind], dp);
        }
        int notTake = compWays(coins, ind - 1, amount, dp);

        return dp[ind][amount] = take + notTake;
    }
};