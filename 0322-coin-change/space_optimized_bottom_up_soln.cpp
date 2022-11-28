class Solution {
public:
    // Time complexity: O(N*T), N = number of coins, T = amount
    // Space complexity: O(T) 
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        // vector<vector<int>> dp(size, vector<int>(amount + 1, -1));
        
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) {
                prev[t] = t/coins[0];
            }
            else {
                prev[t] = 1e9;
            }
        }
        
        for (int ind = 1; ind < size; ind++) {
            for (int t = 0; t <= amount; t++) {
                int take = 1e9;
                int notTake = prev[t];

                if (coins[ind] <= t) {
                    take = 1 + cur[t - coins[ind]];
                }

                cur[t] =  min(take, notTake);
            }
            prev = cur;
        }
        
        
        int res = prev[amount];
        if (res != 1e9) {
            return res;
        }
        return -1;
    }
};
