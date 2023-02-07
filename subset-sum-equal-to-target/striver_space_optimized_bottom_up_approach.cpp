// Time complexity: O(n*target), Space complexity: O(target)
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>curr(k + 1, false);
    vector<bool> prev(k + 1, false);

    // Base case: target == 0
    curr[0] = 1;
    prev[0] = 1;

    // Base case: i == 0
    curr[arr[0]] = true;
    prev[arr[0]] = true;


    for (int ind = 1; ind < n; ind++) {
        for (int tar = 1; tar <= k; tar++) {
            bool take = false;

            if (tar >= arr[ind]) {
                take = prev[tar - arr[ind]];
            }
            bool notTake = prev[tar];

            curr[tar] = take || notTake;

        }
        prev = curr;
    }

    return prev[k];
}