#include <bits/stdc++.h> 
// Time complexity: O(N*maxW), Space complexity: O(N*maxW)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // Base case: All wts >= weight[0] can be stolen.
	for (int w = weight[0]; w <= maxWeight; w++) {
		dp[0][w] = value[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int maxW = 1; maxW <= maxWeight; maxW++) {
			int notPick = dp[ind - 1][maxW];

			int pick = 0;
			if (maxW >= weight[ind]) {
				pick = dp[ind - 1][maxW - weight[ind]] + value[ind];
			}
			dp[ind][maxW] = max(pick, notPick);
		}
	}
	
	return dp[n - 1][maxWeight];
}