// Time complexity: O(w*n), Space complexity: O(w)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> curr(w + 1, 0);
    vector<int> prev(w + 1, 0);

    for (int wt = 0; wt <= w; wt++) {
        if (wt >= weight[0]) {
            int mult = wt/weight[0];
            prev[wt] = curr[wt] = mult*profit[0];
        }
    }

    for (int ind = 1; ind < n; ind++) {
        for (int wt = 0; wt <= w; wt++) {
            int take = 0, notTake = 0;
            if (wt >= weight[ind]) {
                take = profit[ind] + curr[wt - weight[ind]];
            }
            notTake = prev[wt];
            curr[wt] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[w];
}