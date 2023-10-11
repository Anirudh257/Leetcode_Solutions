// Time complexity: O(n), Space complexity: O(1)

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights) {
	int one_prev = 0, curr = 0, two_prev = 0;
	
	for (int ind = 1; ind < n; ind++) {
		int one_step = INT_MAX, two_step = INT_MAX;

		if (ind - 1 >= 0) {
			one_step = abs(heights[ind] - heights[ind - 1]) + one_prev;
		}

		if (ind - 2 >= 0) {
			two_step = abs(heights[ind] - heights[ind -2]) + two_prev;
		}
		curr = min(one_step, two_step);
		two_prev = one_prev;
		one_prev = curr;

	}

	return one_prev;

}

