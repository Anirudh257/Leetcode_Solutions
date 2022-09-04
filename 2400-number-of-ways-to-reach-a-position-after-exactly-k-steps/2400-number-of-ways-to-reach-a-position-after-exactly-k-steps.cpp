class Solution {
public:
    // Time complexity: O(mn), m = positions = 4000, n = number of steps = 1000, Space complexity: O(mn)
    int numberOfWays(int startPos, int endPos, int k) {
        for (int i = 0; i < 3001; i++) {
            for (int j = 0; j < 1001; j++) {
                dp[i][j] = -1;
            }
        }       
        
        return countWays(startPos, endPos, k);
        
    }
private:
    long long int dp[4001][1001];
    long long int mod = 1e9 + 7;
    
    long long countWays(int currPos, int endPos, int k) {
        if (k == 0 && currPos == endPos) {
            return 1;
        }
        
        if (k == 0) {
            return 0;
        }
        
        if (dp[currPos + 1000][k] != -1) {
            return dp[currPos + 1000][k];
        }
        
        long long numWays = countWays(currPos - 1, endPos, k - 1);
        numWays += countWays(currPos + 1, endPos, k - 1);
        
        return dp[currPos + 1000][k] = numWays%mod;
        
    }
    
};