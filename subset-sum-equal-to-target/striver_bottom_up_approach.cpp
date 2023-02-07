// Time complexity: O(n*target), Space complexity: O(n*target) +
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    // Base case: target == 0
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    // Base case: i == 0
    dp[0][arr[0]] = true;


    for (int ind = 1; ind < n; ind++) {
        for (int tar = 1; tar <= k; tar++) {
            bool take = false;

            if (tar >= arr[ind]) {
                take = dp[ind - 1][tar - arr[ind]];
            }
            bool notTake = dp[ind - 1][tar];

            dp[ind][tar] = take || notTake;

        }
    }

    return dp[n - 1][k];
}