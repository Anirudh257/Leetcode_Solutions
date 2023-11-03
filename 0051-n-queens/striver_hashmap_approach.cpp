// Time complexity: O(n!), Space complexity: O(n)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> configs;
        vector<string> config(n);
        string s(n, '.');

        for (int i = 0; i < n; i++) {
            config[i] = s;
        }

        vector<bool> leftRow(n, false), upperDiag(2*n - 1, false), lowerDiag(2*n-1, false);

        compConfigs(config, configs, 0, n, leftRow, upperDiag, lowerDiag);

        return configs;
    }
private:
    void compConfigs(vector<string>& config, vector<vector<string>>& configs, int col, int n, vector<bool>& leftRow, vector<bool>& upperDiag, vector<bool>& lowerDiag) {
        if (col == n) {
            configs.push_back(config);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (!leftRow[row] && !lowerDiag[row + col] && !upperDiag[n - 1 + col - row]) {
                config[row][col] = 'Q';
                leftRow[row] = true;
                lowerDiag[row + col] = true;
                upperDiag[n - 1 + col - row] = true;
                compConfigs(config, configs, col + 1, n, leftRow, upperDiag, lowerDiag);
                config[row][col] = '.';
                leftRow[row] = false;
                lowerDiag[row + col] = false;
                upperDiag[n - 1 + col - row] = false;
            }
        }

    }
};