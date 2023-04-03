#include <bits/stdc++.h> 
// Time complexity: O(n*w), Space complexity: O(w)
int compProf(int ind, int w, vector<int>& profit, vector<int>& weight, vector<vector<int>>& dp) {
    if (ind < 0) {
        return 0;
    }

    if (w == 0) {
        return 0;
    }

    if (dp[ind][w] != -1) {
        return dp[ind][w];
    }

    int notTake = compProf(ind - 1, w, profit, weight, dp);
    int take = 0;
    if (w >= weight[ind]) {
        take = profit[ind] + compProf(ind, w - weight[ind], profit, weight, dp);
    }
    return dp[ind][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    vector<int> prev(w + 1, 0), curr(w + 1, 0);
    
    for (int wt = weight[0]; wt <= w; wt++) {
            curr[wt] = prev[wt] = profit[0]*((int)wt/weight[0]);
    }

    for (int ind = 1; ind < n; ind++) {
        for (int wt = 0; wt <= w; wt++) {
            int notTake = 0, take = 0;
            notTake = prev[wt];
            take = INT_MIN;
            if (wt >= weight[ind]) {
                take = profit[ind] + curr[wt - weight[ind]];
            }
            curr[wt] = max(take, notTake);
        }
        prev = curr;
    }
    
    return prev[w];
}
