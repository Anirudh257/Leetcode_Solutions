// Time complexity: O(n*amount), Space complexity: O(n*amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<vector<int>> dp(size, vector<int>(amount + 1, -1));

        for (int i = 0; i < size; i++) {
            dp[i][0] = 1;
        }

        for (int ind = 0; ind < size; ind++) {
            for (int amt = 1; amt <= amount; amt++) {
                int take = 0, notTake = 0;

                if (amt >= coins[ind]) {
                    take = dp[ind][amt - coins[ind]];
                }
                
                if (ind > 0) {
                    notTake = dp[ind - 1][amt];
                }

                dp[ind][amt] = take + notTake;

            }
        }


        return dp[size - 1][amount];
    }
};