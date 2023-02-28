#include <bits/stdc++.h> 
// Time complexity: O(N*tar), Space complexity: O(N*tar)

int findWays(vector<int> &num, int tar){
    int size = num.size();
    vector<vector<int>> dp(size, vector<int>(tar + 1, 0));

    for (int i = 0; i < size; i++) {
        dp[i][0] = 1;
    }

    if (num[0] <= tar) {
        dp[0][num[0]] = 1;
    }

    if (num[0] == 0) {
        dp[0][0] = 2;
    }

    for (int ind = 1; ind < size; ind++) {
        for (int t = 0; t <= tar; t++) {
            int notPick = dp[ind - 1][t];
            int pick = 0;
            if (t >= num[ind]) {
                pick = dp[ind - 1][t - num[ind]];
            }
            dp[ind][t] = pick + notPick;
        }
    }

    return dp[size - 1][tar];
}