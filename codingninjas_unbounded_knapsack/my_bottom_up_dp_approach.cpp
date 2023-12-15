// Time complexity: O(w*n), Space complexity: O(w*n)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(w + 1, vector<int>(n, 0));

    for (int wt = 0; wt <= w; wt++) {
        if (wt >= weight[0]) {
            int mult = wt/weight[0];
            dp[wt][0] = mult*profit[0];
        }
    }

    for (int ind = 1; ind < n; ind++) {
        for (int wt = 0; wt <= w; wt++) {
            int take = 0, notTake = 0;
            if (wt >= weight[ind]) {
                
                take = profit[ind] + dp[wt - weight[ind]][ind];
            }
            notTake = dp[wt][ind - 1];
            dp[wt][ind] = max(take, notTake);
        }
    }

    return dp[w][n - 1];
}