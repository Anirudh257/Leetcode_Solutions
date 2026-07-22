#include <bits/stdc++.h> 
// Time complexity: O(N*maxW), Space complexity: O(N*maxW) + Auxiliary Stack Space: O(maxW)
int maxAmt(vector<int>& weight, vector<int>& value, int ind, int maxW, vector<vector<int>>& dp) {
	if (maxW == 0) {
		return 0;
	}
	if (ind == 0) {
		if (maxW >= weight[ind]) {
			return value[ind]; 
		}
		else {
			return 0;
		}
	}

	if (dp[ind][maxW] != -1) {
		return dp[ind][maxW];
	}

	int notPick = maxAmt(weight, value, ind - 1, maxW, dp);

	int pick = 0;
	if (maxW >= weight[ind]) {
		pick = maxAmt(weight, value, ind - 1, maxW - weight[ind], dp) + value[ind];
	}
	return dp[ind][maxW] = max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
	return maxAmt(weight, value, n - 1, maxWeight, dp);	
}