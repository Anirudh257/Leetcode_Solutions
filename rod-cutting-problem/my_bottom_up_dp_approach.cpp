// Time complexity: O(n^2), Space complexity: O(n^2)
int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int len = 0; len <= n; len++) {
		dp[0][len] = len*price[0];
	}

	for (int ind = 1; ind <= n; ind++) {
		for (int len = 0; len <= n; len++) {
			int take = 0, rodLen = ind + 1;
			
            if (len >= rodLen) {
				take = price[ind] + dp[ind][len - rodLen];
			}
			int notTake = dp[ind - 1][len];
			dp[ind][len] = max(take, notTake);
		}
	}
	return dp[n][n];
}
