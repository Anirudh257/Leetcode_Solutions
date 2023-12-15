// Time complexity: O(w*n), Space complexity: O(w*n) + Auxiliary Space: O(w + n)
int compMaxProfit(int w, int ind, vector<int> &profit, vector<int> &weight, vector<vector<int>>& dp) {
    if (dp[w][ind] != -1) {
        return dp[w][ind];
    }

    if (ind == 0) {
        if (w >= weight[ind]) {
            int mult = w/weight[ind];
            return  profit[ind]*mult;
        }
        else {
            return 0;
        }
    }

    int take = 0, notTake = 0;

    if (w >= weight[ind]) {
        take = profit[ind] + compMaxProfit(w - weight[ind], ind, profit, weight, dp);
    }

    notTake = compMaxProfit(w, ind - 1, profit, weight, dp);

    return dp[w][ind] = max(take, notTake);

}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(w + 1, vector<int>(n, -1));
    return compMaxProfit(w, n - 1, profit, weight, dp);
}