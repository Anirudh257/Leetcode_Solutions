// Time complexity: O(N*Sum), Space complexity: O(sum)
#include <bits/stdc++.h> 
int countPartitions(int n, int d, vector<int> &arr) {
    // Constraints: S1 + S2 = TotSum
    // S1 - S2 = D
    // TotSum = (S2 + D) + S2 => 2S2 + D = TotSum
    // S2 = (TotSum - D)/2. Count all subsets.
    int sum = 0, mod = (int)(pow(10, 9) + 7);
    for (auto &x : arr) {
        sum += x;
    }

    if (sum - d < 0 || (sum - d) % 2 != 0) {
        return 0;
    }
    
    int reqSum = (sum - d)/2;
    vector<int> cur(reqSum + 1, 0), prev(reqSum + 1, 0);

    // Base case:
    if (arr[0] == 0) {
        cur[0] = prev[0] = 2;
    }
    else {
        cur[0] = prev[0] = 1;
    }

    if (arr[0] != 0 && arr[0] <= reqSum) {
        prev[arr[0]] = cur[arr[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= reqSum; target++) {
            int pick = 0;
            int notPick = prev[target];

            if (arr[ind] <= target) {
                pick = prev[target - arr[ind]];
            }
            cur[target] = (pick + notPick)%mod;            
        }
        prev = cur;
    }
    return prev[reqSum];

}


