#include <bits/stdc++.h> 
// Time complexity: O(n*w), Space complexity: O(n*w)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    
    for (int wt = weight[0]; wt <= w; wt++) {
            dp[0][wt] = profit[0]*((int)wt/weight[0]);
    }

    for (int ind = 1; ind < n; ind++) {
        for (int wt = 0; wt <= w; wt++) {
            int notTake = 0, take = 0;
            notTake = dp[ind - 1][wt];
            take = INT_MIN;
            if (wt >= weight[ind]) {
                take = profit[ind] + dp[ind][wt - weight[ind]];
            }
            dp[ind][wt] = max(take, notTake);
        }
    }
    
    return dp[n - 1][w];
}
