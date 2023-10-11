// Time complexity: O(n), Space complexity: O(n)
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights) {
	vector<int> dp(n, 0);

	
	for (int ind = 1; ind < n; ind++) {
		int one_step = INT_MAX, two_step = INT_MAX;

		if (ind - 1 >= 0) {
			one_step = abs(heights[ind] - heights[ind - 1]) + dp[ind - 1];
		}

		if (ind - 2 >= 0) {
			two_step = abs(heights[ind] - heights[ind -2]) + dp[ind - 2];
		}

		dp[ind] = min(one_step, two_step);
	}

	return dp[n - 1];
}

