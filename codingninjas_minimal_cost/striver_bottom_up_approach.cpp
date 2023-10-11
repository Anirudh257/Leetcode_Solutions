// Time complexity: O(nk), Space complexity: O(n) 
int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n, 0);

    for (int ind = 1; ind < n; ind++) {
        int jumpCost = INT_MAX;
        int minCost = INT_MAX;
         
        for (int i = 1; i <= k; i++) {
            if (ind - i >= 0) {
                jumpCost = abs(height[ind] - height[ind - i]) + dp[ind - i];
                minCost = min(minCost, jumpCost);
            }
        }

        dp[ind] = minCost;
    }

    return dp[n - 1];
}