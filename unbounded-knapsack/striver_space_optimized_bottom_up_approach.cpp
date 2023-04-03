#include <bits/stdc++.h> 
// Time complexity: O(n*w), Space complexity: O(w)

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w + 1, 0);
    
    for (int wt = weight[0]; wt <= w; wt++) {
            prev[wt] = profit[0]*((int)wt/weight[0]);
    }

    for (int ind = 1; ind < n; ind++) {
        for (int wt = 0; wt <= w; wt++) {
            int notTake = 0, take = 0;
            notTake = prev[wt];
            take = INT_MIN;
            if (wt >= weight[ind]) {
                take = profit[ind] + prev[wt - weight[ind]];
            }
            prev[wt] = max(take, notTake);
        }
    }
    
    return prev[w];
}
