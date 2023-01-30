class Solution {
public:
    // Time complexity: O(N), Space complexity: O(N)
    int findJudge(int n, vector<vector<int>>& trust) {
        int jud = -1;

        vector<int> trustScores(n + 1, 0);
        
        for (auto &x : trust) {
            trustScores[x[0]]--; // Outdegree-1, indeg =+ 1
            trustScores[x[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (trustScores[i] == n - 1) {
                return jud = i;
            }
        }

        return jud;
    }
};
