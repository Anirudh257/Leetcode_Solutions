// Time complexity: O(n^2), Space complexity: O(n^2) + Auxiliary Stack Space: O(n)
int maxCost(vector<int>& price, int ind, int len, vector<vector<int>>& dp) {
	if (len == 0) {
		return 0;
	}
	if (ind == 0){
		return len*price[0];
	}
	if (dp[ind][len] != -1) {
		return dp[ind][len];
	}
	int take = 0;
    int rodLen = ind + 1;
	if (len >= rodLen) {
		take = price[ind] + maxCost(price, ind, len - rodLen, dp);
	}
	int notTake = maxCost(price, ind - 1, len, dp);
	return dp[ind][len] = max(take, notTake);
}
int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	return maxCost(price, n, n, dp);
}
