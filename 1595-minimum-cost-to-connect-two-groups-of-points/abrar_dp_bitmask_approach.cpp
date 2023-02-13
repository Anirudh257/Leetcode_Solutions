// Time complexity: O((n*2^m)*m), m = time to compute 1 state
// Space complexity: O(n*2^m)
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int size1 = cost.size(), size2 = cost[0].size();

        // Stores the possibility of connections that group 2 can have = 2^size2
        // Each node has 2 options - connected/not connected.

        int bSize = 1 << size2;
        vector<vector<int>> dp(size1 + 1, vector<int>(bSize));

        // Minimum way to connect a node in group2.
        vector<int> g2Mins(size2, INT_MAX);

        for (int i = 0; i < size2; i++) {
            for (int j = 0; j < size1; j++) {
                g2Mins[i] = min(g2Mins[i], cost[j][i]);
            }
        }

        int ans = compDFS(0, 0, cost, dp, g2Mins);

        return ans;
    }
private:
    int compDFS(int g1Idx, int grp2, vector<vector<int>>& cost, vector<vector<int>>& dp, vector<int>& g2Mins) {
        int g1Size = cost.size(), g2Size = cost[0].size();
        if (dp[g1Idx][grp2] > 0) {
            return dp[g1Idx][grp2];
        }

        int sumCost = 0;
        if (g1Idx == g1Size) {
            for (int i = 0; i < g2Size; i++) {
                if ((grp2 & (1 << i)) == 0) { // signify which node of group2 has already been connected.
                    sumCost += g2Mins[i];
                }
            }
        }
        else {
            sumCost = INT_MAX;
            for (int i = 0; i < g2Size; i++) {
                int c = cost[g1Idx][i];
                sumCost = min(sumCost, c + compDFS(g1Idx + 1, grp2 | (1 << i), cost, dp, g2Mins));
            }
        }
        return dp[g1Idx][grp2] = sumCost;

    }
};