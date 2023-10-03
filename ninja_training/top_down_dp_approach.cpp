// Time complexity: O(n*3), Space complexity: O(n*3) + Auxiliary stack space: O(n)
int compMaxPts(int ind, vector<vector<int>> &points, int actInd, vector<vector<int>>& dp) {
    if (ind < 0) {
        return 0;
    }

    if (dp[ind][actInd] != -1) {
        return dp[ind][actInd];
    }

    int currPts = points[ind][actInd];

    int take0 = 0, take1 = 0, take2 = 0;

    if (actInd == 0) {
        take1 = compMaxPts(ind - 1, points, 1, dp);
        take2 = compMaxPts(ind - 1, points, 2, dp);
    }

    if (actInd == 1){
        take0 = compMaxPts(ind - 1, points, 0, dp);
        take2 = compMaxPts(ind - 1, points, 2, dp);
    }

    if (actInd == 2) {
        take0 = compMaxPts(ind - 1, points, 0, dp);
        take1 = compMaxPts(ind - 1, points, 1, dp);
    }

    return dp[ind][actInd] = currPts + max(max(take0, take1), take2);

}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(3, -1));
    return max(max(compMaxPts(n - 1, points, 0, dp), compMaxPts(n - 1, points, 1, dp)),
     compMaxPts(n - 1, points, 2, dp)); 
}