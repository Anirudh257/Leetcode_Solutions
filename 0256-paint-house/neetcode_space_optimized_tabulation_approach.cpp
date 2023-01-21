// Time complexity: O(3N), Space complexity: O(1) 
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        vector<int> dp(3, 0);

        int pickRed = 0, pickBlue = 0, pickGreen = 0;

        for (int i = 0; i < size; i++) {
            pickRed = costs[i][0] + min(dp[1], dp[2]);
            pickBlue = costs[i][1] + min(dp[0], dp[2]);
            pickGreen = costs[i][2] + min(dp[0], dp[1]);
            dp = {pickRed, pickBlue, pickGreen};
        }

        return min({pickRed, pickBlue, pickGreen});
    }
};
