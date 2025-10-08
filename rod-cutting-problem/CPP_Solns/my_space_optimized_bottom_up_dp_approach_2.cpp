// Time complexity: O(n^2), Space complexity: O(n)
int cutRod(vector<int> &price, int n){
	vector<int> prev(n + 1, 0);
	for (int len = 0; len <= n; len++) {
		prev[len] = len*price[0];
	}

	for (int ind = 1; ind <= n; ind++) {
		for (int len = 0; len <= n; len++) {
			int take = 0, rodLen = ind + 1;
			
            if (len >= rodLen) {
				take = price[ind] + prev[len - rodLen];
			}
			int notTake = prev[len];
			prev[len] = max(take, notTake);
		}
	}
	return prev[n];
}
