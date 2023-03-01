#include <bits/stdc++.h> 

// Time complexity: O(N*tar), Space complexity: O(N*tar) + Auxiliary stack space: O(tar)

int countWays(vector<int>& num, int tar, int ind, vector<vector<int>>& dp) {

    if (ind == 0) {
        if (tar == 0 && num[0] == 0) {
            return 2;
        }
        if (num[0] == tar || tar == 0) {
            return 1;
        }
        return 0;
    }

    if (dp[ind][tar] != -1) {
        return dp[ind][tar];
    }

    // not pick
    int pick = 0;
    int notPick = countWays(num, tar, ind - 1, dp);

    if (tar >= num[ind]) {
        pick = countWays(num, tar - num[ind], ind - 1, dp);
    }
    return dp[ind][tar] = pick + notPick;
}

int findWays(vector<int> &num, int tar) {
    int size = num.size();
    vector<vector<int>> dp(size, vector<int>(tar + 1, -1));
    return countWays(num, tar, size - 1, dp);
}