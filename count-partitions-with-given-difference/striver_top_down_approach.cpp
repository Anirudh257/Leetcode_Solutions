// Time complexity: O(N*Sum), Space complexity: O(N*sum) + Auxiliary Stack Space: O(sum)
#include <bits/stdc++.h> 
int mod = (int)(pow(10, 9) + 7);
int countSubSets(int ind, vector<int>& arr, int reqSum, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (reqSum == 0 && arr[ind] == 0) {
            return 2;
        }
        if (reqSum == 0 || reqSum == arr[ind]) {
            return 1;
        } 
        return 0;
    }

    if (dp[ind][reqSum] != -1) {
        return dp[ind][reqSum];
    }

    int pick = 0;
    int notPick = countSubSets(ind - 1, arr, reqSum, dp);

    if (arr[ind] <= reqSum) {
        pick = countSubSets(ind - 1, arr, reqSum - arr[ind], dp);
    }
    return dp[ind][reqSum] = (pick + notPick)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Constraints: S1 + S2 = TotSum
    // S1 - S2 = D
    // TotSum = (S2 + D) + S2 => 2S2 + D = TotSum
    // S2 = (TotSum - D)/2. Count all subsets.
    int sum = 0;
    for (auto &x : arr) {
        sum += x;
    }

    if (sum - d < 0 || (sum - d) % 2 != 0) {
        return 0;
    }
    int reqSum = (sum - d)/2;
    vector<vector<int>> dp(n, vector<int>(reqSum + 1, -1));

    return countSubSets(n - 1, arr, reqSum, dp);

}


