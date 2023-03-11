// Time complexity: O(n*amount), Space complexity: O(amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        prev[0] = curr[0] = 1;

        for (int ind = 0; ind < size; ind++) {
            for (int amt = 1; amt <= amount; amt++) {
                int take = 0, notTake = 0;

                if (amt >= coins[ind]) {
                    take = curr[amt - coins[ind]];
                }
                
                if (ind > 0) {
                    notTake = prev[amt];
                }

                curr[amt] = take + notTake;
            }
            prev = curr;
        }


        return prev[amount];
    }
};