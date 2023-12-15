#include <bits/stdc++.h> 
// Time complexity: O(N*N*N) + Space complexity: O(N*N) + Auxiliary Stack
// Space: O(N)
int compMinSteps(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if (i == j) { // It represents just 1 matrix A[1, 1] 
    // so 0 multiplications
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // Need to try all possible configurations of brackets and find
    // the minimum number of multiplications required.
    // arr = [10, 20, 30, 40, 50]
    // i = 1, j = 4, k -> 1 to 3
    // k = 1 A(BCD) 
    // k = 2 (AB)(CD)
    // k = 3 (ABC)D
    int minSteps = 1e9;
    for (int k = i; k <= j - 1; k++) {
        int numSteps = arr[i - 1]*arr[k]*arr[j] + compMinSteps(arr, i, k, dp) + compMinSteps(arr, k + 1, j, dp);
        minSteps = min(minSteps, numSteps);
    }
    return dp[i][j] = minSteps;
}

int matrixMultiplication(vector<int> &arr, int N){
    // We need to get the best way to place brackets to minimize the 
    // number of multiplications. 
    // size N denotes (N - 1) matrix multiplcations.
    // N = 5 and arr = [10, 20, 30, 40, 50] => A x B x C x D
    // A = (10 x 20), B = (20 x 30), C = (30 x 40), D = (40 x 50)
    // ith matrix will have dimensions: arr[i - 1] x arr[i]
    // Need to place the brackets to get the least number of 
    // multiplications: min[(A)(BCD), (AB)(CD), (ABC)(D), ...]
    // (AB) = 10 x 20 x 30 steps
    // (A)(BCD) = 10 x 20 x 50 steps 
    // If k represents the bracket place, 
    // number of multiplications = A[i - 1]*A[k]*A[j]
    vector<vector<int>> dp(N, vector<int>(N, -1));

    return compMinSteps(arr, 1, N - 1, dp);
}