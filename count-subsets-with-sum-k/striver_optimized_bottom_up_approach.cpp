#include <bits/stdc++.h> 
// Time complexity: O(N*tar), Space complexity: O(tar)

int findWays(vector<int> &num, int tar){
    int size = num.size();
    vector<int> prev(tar + 1, 0), cur(tar + 1, 0);

    cur[0] = prev[0] = 1;
    


    if (num[0] <= tar) {
        cur[num[0]] = prev[num[0]] = 1;
    }

    if (num[0] == 0) {
        prev[0] = cur[0] = 2;
    }

    for (int ind = 1; ind < size; ind++) {
        
        for (int t = 0; t <= tar; t++) {
            int notPick = prev[t];
            int pick = 0;
            if (t >= num[ind]) {
                pick = prev[t - num[ind]];
            }
            cur[t] = pick + notPick;
        }
        prev = cur;
    }

    return prev[tar];
}