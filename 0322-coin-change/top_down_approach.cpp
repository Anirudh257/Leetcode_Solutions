class Solution {
public:
    // Time complexity: O(N*T), N = number of coins, T = amount
    // Space complexity: O(N*T) 
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<vector<int>> dp(size, vector<int>(amount + 1, -1));
        
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) {
                dp[0][t] = t/coins[0];
            }
            else {
                dp[0][t] = 1e9;
            }
        }
        
        for (int ind = 1; ind < size; ind++) {
            for (int t = 0; t <= amount; t++) {
                int take = 1e9;
                int notTake = dp[ind - 1][t];

                if (coins[ind] <= t) {
                    take = 1 + dp[ind][t - coins[ind]];
                }

                dp[ind][t] =  min(take, notTake);
                
            }
        }
        
        
        int res = dp[size - 1][amount];
        if (res != 1e9) {
            return res;
        }
        return -1;
    }
};
