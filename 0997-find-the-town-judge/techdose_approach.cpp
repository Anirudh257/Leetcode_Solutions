class Solution {
public:
    // Time complexity: O(N), Space complexity: O(2N)
    int findJudge(int n, vector<vector<int>>& trust) {
        int jud = -1;

        //[0] -> trusts, [1] - trusted by
        vector<vector<int>> trustVec(2, vector<int>(n + 1));

        for (auto &x : trust) {
            int fir = x[0], sec = x[1];
            trustVec[0][fir]++;
            trustVec[1][sec]++;
        }

        for (int i = 1; i <= n; i++) {
            if (trustVec[1][i] == n - 1 && trustVec[0][i] == 0) {
                jud = i;
            }
        }

        return jud;
    }
};
