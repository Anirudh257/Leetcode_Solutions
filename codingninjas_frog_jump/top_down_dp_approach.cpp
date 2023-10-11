// Time complexity: O(n), Space complexity: O(n) + Auxiliary Stack Space: O(n)
#include <bits/stdc++.h> 

int compEnergy(vector<int>& heights, vector<int>& dp, int ind) {
	if (ind == 0) {
		return 0;
	}
	if (ind < 0) {
		return INT_MAX;
	}

	if (dp[ind] != -1) {
		return dp[ind];
	}

	int one_step = INT_MAX, two_step = INT_MAX;

	if (ind - 1 >= 0) {
		one_step = abs(heights[ind] - heights[ind - 1]) + compEnergy(heights, dp, ind - 1);
	}

	if (ind - 2 >= 0) {
		two_step = abs(heights[ind] - heights[ind - 2]) + compEnergy(heights, dp, ind - 2);
	}

	return dp[ind] = min(one_step, two_step);
}

int frogJump(int n, vector<int> &heights) {
	vector<int> dp(n, -1);
	return compEnergy(heights, dp, n - 1);
}

