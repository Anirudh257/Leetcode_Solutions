#include <bits/stdc++.h> 
// Time complexity: O(N*3), Space complexity: O(N^2)
int matrixMultiplication(vector<int> &arr, int N) {
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int st = N - 1; st >= 1; st--) {
        for (int end = st + 1; end < N; end++) {
            int minMults = 1e9;
            for (int k = st; k < end; k++) {
                int mults = arr[st - 1]*arr[k]*arr[end] + dp[st][k] + dp[k + 1][end];
                minMults = min(minMults, mults);
            }
            dp[st][end] = minMults;
        }
    }

    return dp[1][N - 1];
}