#include <bits/stdc++.h> 
// Time complexity: O(N*N*N) + Space complexity: O(N*N) 
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
    
    int dp[N][N];

    // Copy the base case
    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    // Look at the changing parameters and reverse the iteration.
    // i -> 1 to N - 1 becomes N - 1 to 1
    // j -> N - 1 to i becomes i + 1 to N - 1 (as j always has to be greater than i).
    for (int i = N -  1; i >= 1; i--) {
        for (int j = i + 1; j < N; j++) {
            int minSteps = 1e9;
            for (int k = i; k <= j - 1; k++) {
                int numSteps = arr[i - 1]*arr[k]*arr[j] + dp[i][k] + dp[k + 1][j];
                minSteps = min(minSteps, numSteps);
            }
            dp[i][j] = minSteps;
        }
    }

    return dp[1][N - 1];
    // return compMinSteps(arr, 1, N - 1, dp);
}