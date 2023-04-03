#include <bits/stdc++.h> 

// Time complexity: O(n^3), Space complexity: O(n^2) + Auxiliary Stack Space: O(n)

int compMultns(int st, int end, vector<int>& arr, vector<vector<int>>& dp) {
    if (st == end) {
        return 0;
    }
    if (dp[st][end] != -1) {
        return dp[st][end];
    }

    int minMults = 1e9;

    for (int k = st; k < end; k++) {
        int mults = arr[st - 1]*arr[k]*arr[end] + compMultns(st, k,arr, dp) + compMultns(k + 1, end, arr, dp);
        minMults = min(minMults, mults);
    }

    return dp[st][end] = minMults;

}

int matrixMultiplication(vector<int> &arr, int N) {
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return compMultns(1, N - 1, arr, dp);
}