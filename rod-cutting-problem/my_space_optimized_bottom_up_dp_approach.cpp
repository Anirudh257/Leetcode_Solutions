// Time complexity: O(n^2), Space complexity: O(n^2)
int cutRod(vector<int> &price, int n){
	vector<int> prev(n + 1, 0);
	for (int len = 0; len <= n; len++) {
		prev[len] = len*price[0];
	}

	for (int ind = 1; ind <= n; ind++) {
		vector<int> curr(n + 1, 0);
		for (int len = 0; len <= n; len++) {
			int take = 0, rodLen = ind + 1;
			
            if (len >= rodLen) {
				take = price[ind] + curr[len - rodLen];
			}
			int notTake = prev[len];
			curr[len] = max(take, notTake);
		}
		prev = curr;
	}
	return prev[n];
}
