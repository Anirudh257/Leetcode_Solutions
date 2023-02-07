// Time complexity: O(n*target), Space complexity: O(n*target) +
// Auxiliary stack space: O(n)
#include <bits/stdc++.h>
bool checkSubset(vector<vector<int>>& dp, int i, int target, vector<int>& arr) {
    if (i == 0) {
        return arr[i] == target;
    }

    if (target == 0) {
        return true;
    }

    if (dp[i][target] != -1) {
        return dp[i][target];
    }

    bool take = false;

    if (target >= arr[i]) {
        take = checkSubset(dp, i - 1, target - arr[i], arr);
    }
    bool notTake = checkSubset(dp, i - 1, target, arr);

    return dp[i][target] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    bool ans = checkSubset(dp, n - 1, k, arr);
    return ans;
}