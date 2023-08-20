// Time complexity: O(mn), Space complexity: O(1)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        board = updateBoard(board, m, n);

        for (int i  = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -5) {
                    board[i][j] = 1;
                }
                else if (board[i][j] == -10) {
                    board[i][j] = 0;
                }
            }
        }
        return;
    }
private:
    bool isValid(int i, int j, int m, int n) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            return true;
        }
        return false;
    }

    int compNeigh(vector<vector<int>>& board, int currX, int currY, int m, int n) {
        int numNeigh = 0;

        for (int i = currX - 1; i <= currX + 1; i++) {
            for (int j = currY - 1; j <= currY + 1; j++) {
                if (!isValid(i, j, m, n)) {
                    continue;
                }
                if (i == currX && j == currY) {
                    continue;
                }
                if (board[i][j] == -10 || board[i][j] == 1) {
                    numNeigh++;
                }
            }
        }
        return numNeigh;
    }

    vector<vector<int>> updateBoard(vector<vector<int>>& board, int m, int n) {

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int currCond = board[i][j];

                int numNeigh = compNeigh(board, i, j, m, n);

                if (currCond == 1) {
                    if (numNeigh < 2 || numNeigh > 3) {
                        board[i][j] = -10;
                    }
                }
                else {
                    if (numNeigh == 3) {
                        board[i][j] = -5;
                    }
                }
            }
        }
        return board;
    }
};