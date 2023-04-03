#include <bits/stdc++.h> 
// Time complexity: O(nw), Space complexity: O(nw) + Auxiliary Stack Space: O(w)
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
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return compProf(n - 1, w, profit, weight, dp);
}
