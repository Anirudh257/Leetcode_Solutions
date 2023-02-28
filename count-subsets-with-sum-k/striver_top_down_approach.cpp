#include <bits/stdc++.h> 

int countWays(vector<int>& num, int tar, int ind, vector<vector<int>>& dp) {
    // if (ind < 0) {
    //     return 0;
    // }

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
    // for (int i = 0; i < size; i++) {
    //     dp[i][0] = 1;
    // }

    // dp[0][num[0]] = 1;

    // for (int i = 1; i < size; i++) {
    //     for (int t = 1; t <= tar; t++) {
    //         int pick = 0;
    //         int notPick = dp[i - 1][tar];
    //         if (t >= num[i]) {
    //             pick = dp[i - 1][t - num[i]];
    //         }
    //         dp[i][t] = pick + notPick;
    //     }
    // }

    // return dp[size - 1][tar];
    return countWays(num, tar, size - 1, dp);
}