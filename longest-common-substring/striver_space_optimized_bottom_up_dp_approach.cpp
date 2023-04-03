#include <bits/stdc++.h> 
// Time complexity: O(N^2), Space complexity: O(N)

int lcs(string &str1, string &str2){
	int len1 = str1.length(), len2 = str2.length();
	// vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	vector<int> cur(len2 + 1), prev(len2 + 1);
	int maxLen = 0;

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				cur[j] = 1 + prev[j - 1];
				maxLen = max(maxLen, cur[j]);
			}
			else {
				cur[j] = 0;
			}
		}
		prev = cur;
	}

	return maxLen;
}