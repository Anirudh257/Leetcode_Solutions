#include <bits/stdc++.h> 
// Time complexity: O(n*sum/2), Space complexity: O(sum/2)
int minSubsetSumDifference(vector<int>& arr, int n) {
	int sum = 0;
	for (auto &x: arr) {
		sum += x;
	}

	int reqSum = sum/2;

	// vector<vector<int>> dp(n, vector<int>(sum/2 + 1, 0));

	vector<int> prev(reqSum + 1, 0), curr(reqSum + 1, 0);

	// Base case: sum == 0
	prev[0] = curr[0] = 1;

	// Base case: ind == 0
	if (arr[0] <= reqSum) {
		prev[arr[0]] = curr[arr[0]] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int s = 1; s <= reqSum; s++) {
			bool take = false;
			if (s >= arr[i]) {
				take = prev[s - arr[i]];
			}
			bool notTake = prev[s];

			curr[s] = take | notTake;
		}
		prev = curr;
	}

	int minDiff = INT_MAX;
	for (int s = 0; s <= reqSum; s++) {
		if (prev[s] == 1) {
			int secSum = sum - s;
			minDiff = min(minDiff, abs(secSum - s));
		}
	}

	return minDiff;
}
