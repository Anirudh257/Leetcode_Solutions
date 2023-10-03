// Time complexity: O(n*4)*3[loop of 3], Space complexity: O(n*4) + Auxiliary stack space: O(n)
int compMaxPts(int day, vector<vector<int>> &points, int last, vector<vector<int>> &dp) {
    // Base case
    if (day == 0) {
        int maxPts = 0;
        for (int i = 0; i <= 2; i++) {
            if (i != last) {
                maxPts = max(maxPts, points[0][i]);
            }
        }
        return maxPts;
    }

    if (dp[day][last] != -1) {
        return dp[day][last];
    }
    
    int maxPts = 0;

    for (int i = 0; i <= 2; i++) {
        
        if (i != last) {
            int currPts = points[day][i] + compMaxPts(day - 1, points, i, dp);
            maxPts = max(maxPts, currPts);            
        }
    }
    return dp[day][last] = maxPts;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    // 3 => None of the tasks have been performed yet.
    // 2 changing indices: day: 0, ... n, and last task: 0, ..., 3
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return compMaxPts(n - 1, points, 3, dp); 
}