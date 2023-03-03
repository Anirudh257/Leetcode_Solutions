#include <bits/stdc++.h> 
// Time complexity: O(N*maxW), Space complexity: O(maxW)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<int> prev(maxWeight + 1, 0), cur(maxWeight + 1, 0);

	for (int w = weight[0]; w <= maxWeight; w++) {
		prev[w] = cur[w] = value[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int maxW = 1; maxW <= maxWeight; maxW++) {
			int notPick = prev[maxW];

			int pick = 0;
			if (maxW >= weight[ind]) {
				pick = prev[maxW - weight[ind]] + value[ind];
			}
			cur[maxW] = max(pick, notPick);
		}
		prev = cur;
	}
	
	return prev[maxWeight];
}