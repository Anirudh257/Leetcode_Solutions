#include <bits/stdc++.h> 
// Time complexity: O(N^2), Space complexity: O(N^2)

int lcs(string &str1, string &str2){
	int len1 = str1.length(), len2 = str2.length();
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	int maxLen = 0;

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				maxLen = max(maxLen, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	return maxLen;
}