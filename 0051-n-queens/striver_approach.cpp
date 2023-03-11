// Time complexity: O(n^3), Space complexity: O(n^2) + Auxiliary Stack Space: O(n)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> configs;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        compConfigs(configs, 0, n, board);

        return configs;
    }
private:
    bool isValid(int curX, int curY, vector<string>& board, int n) {
        // Upper-left diagonal attack
        int x = curX, y = curY;
        while(x >= 0 && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x--, y--;
        }

        //left attack
        x = curX, y = curY;
        while(y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            y--;
        }

        //lower-left diagonal attack
        x = curX, y = curY;
        while(x < n && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x++, y--;
        }

        return true;
    }

    void compConfigs(vector<vector<string>>& configs, int col, int n, vector<string>& board) {
        if (col == n) {
            configs.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isValid(row, col, board, n)) {
                board[row][col] = 'Q';
                compConfigs(configs, col + 1, n, board);
                board[row][col] = '.';
            }
        }
    }
};