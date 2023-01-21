// Time complexity: O(3N), Space complexity: O(3N) + Auxiliary Stack Space: O(3N)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        // char pickCol = 'a';
        vector<vector<int>> dp(size, vector<int>(3, -1));
        int pickRed = compCost(costs, size - 1, 'r', dp);
        int pickBlue = compCost(costs, size - 1, 'b', dp);
        int pickGreen = compCost(costs, size - 1, 'g', dp);

        return min({pickRed, pickBlue, pickGreen});
    }
private:
    int compCost(vector<vector<int>>& costs, int ind, char pickCol, vector<vector<int>>& dp) {
        if (ind < 0) {
            return 1e9;
        }

        if (ind == 0) {
            if (pickCol == 'r') {
                return dp[ind][0] = costs[0][0];
            }
            else if (pickCol == 'b') {
                return dp[ind][1] = costs[0][1];
            }
            else {
                return dp[ind][2] = costs[0][2];
            }
        }

        if (pickCol == 'r' && dp[ind][0] != -1) {
            return dp[ind][0];
        }

        if (pickCol == 'b' && dp[ind][1] != -1) {
            return dp[ind][1];
        } 

        if (pickCol == 'g' && dp[ind][2] != -1) {
            return dp[ind][2];
        }       
        
        int pickRed = INT_MAX, pickBlue = INT_MAX, pickGreen = INT_MAX;
        
        if (pickCol == 'r') {
            pickBlue = compCost(costs, ind - 1, 'b', dp);
            pickGreen = compCost(costs, ind - 1, 'g', dp);
            return dp[ind][0] = costs[ind][0] + min(pickBlue, pickGreen);
        }
        else if (pickCol == 'g') {
            pickRed = compCost(costs, ind - 1, 'r', dp);
            pickBlue = compCost(costs, ind - 1, 'b', dp);
            return dp[ind][2] = costs[ind][2] + min(pickRed, pickBlue);
        }
        pickRed = compCost(costs, ind - 1, 'r', dp);
        pickGreen = compCost(costs, ind - 1, 'g', dp);

        return dp[ind][1] =  costs[ind][1] + min(pickRed, pickGreen);        

    }
};
