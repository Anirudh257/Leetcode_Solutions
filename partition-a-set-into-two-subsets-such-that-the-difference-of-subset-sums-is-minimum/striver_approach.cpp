#include <bits/stdc++.h> 
// Time complexity: O(n*sum/2), Space complexity: O(n*sum/2)
int minSubsetSumDifference(vector<int>& arr, int n) {
	int sum = 0;
	for (auto &x: arr) {
		sum += x;
	}

	vector<vector<int>> dp(n, vector<int>(sum/2 + 1, 0));

	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}

	if (arr[0] <= sum) {
		dp[0][arr[0]] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int s = 1; s <= sum/2; s++) {
			bool take = false;
			if (s >= arr[i]) {
				take = dp[i - 1][s - arr[i]];
			}
			bool notTake = dp[i - 1][s];

			dp[i][s] = take | notTake;
		}
	}

	int minDiff = INT_MAX;
	for (int s = 0; s <= sum/2; s++) {
		if (dp[n - 1][s] == 1) {
			int secSum = sum - s;
			minDiff = min(minDiff, abs(secSum - s));
		}
	}

	return minDiff;
}
