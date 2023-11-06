// Time complexity: O(log N), Space complexity: O(1)
int lowerBound(vector<int> arr, int n, int x) {
	int size = arr.size();
	int l = 0, h = n - 1;
	int res = n;

	while(l <= h) {
		int mid = l + (h - l)/2;
		if (arr[mid] < x) {
			l = mid + 1;
		}
		else {
			h = mid - 1;
			res = mid;
		}
	}
	
	return res;
}

