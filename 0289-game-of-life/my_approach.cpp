// Time complexity: O(n^2), Space complexity: O(n^2)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        vector<vector<int>> boardOrig(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boardOrig[i][j] = board[i][j];
            }
        }

        board = compLiveCells(boardOrig, m, n);
        return;
    }

private:

    bool validCell(int i, int j, int m, int n) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            return true;
        }
        return false;
    }

    int compLiveNeigh(int i, int j, int m, int n, vector<vector<int>>& board) {
        int numNeigh = 0;

        for (int st = i - 1; st <= i + 1; st++) {
            for (int end = j - 1; end <= j + 1; end++) {
                if (validCell(st, end, m, n)) {
                    if (st == i && end == j) {
                        continue;
                    }
                    else {
                        numNeigh+=board[st][end];
                    }
                }
            }
        }
        return numNeigh;
    }

    vector<vector<int>> compLiveCells(vector<vector<int>>& board, int m, int n) {
        vector<vector<int>> newBoard(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int currCond = board[i][j];
                // newBoard[i][j] = currCond;
                int numLiveNeigh = compLiveNeigh(i, j, m, n, board);

                if (i == 1 && j == 0) {
                    cout << numLiveNeigh << endl;
                }

                if (currCond == 1) {
                    if (numLiveNeigh == 2 || numLiveNeigh == 3) {
                        newBoard[i][j] = 1;
                    }
                    // else {
                    //     newBoard[i][j] = 0;
                    // }
                }
                else {
                    if (numLiveNeigh == 3) {
                        newBoard[i][j] = 1;
                    }
                    // else {
                    //     newBoard[i][j] = 0;
                    // }
                }
            }
        }
        return newBoard;
    }
};