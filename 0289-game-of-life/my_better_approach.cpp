// Time complexity: O(mn), Space complexity: O(1)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curr = board[i][j];
                int numLiveNeigh = countNeigh(i, j, board, m, n);

                // cout << i << " " << j <<  " " << numLiveNeigh << endl;

                if (curr == 1 || curr == -2) {
                    if (numLiveNeigh < 2) {
                        board[i][j] = -2;
                    }
                    else if (numLiveNeigh == 2 || numLiveNeigh == 3) {
                        board[i][j] = 1;
                    }
                    else if (numLiveNeigh > 3) {
                        board[i][j] = -2;
                    }
                }
                else if (curr == 0 || curr == -1){
                    if (numLiveNeigh == 3) {
                        board[i][j] = -1;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -2) {
                    board[i][j] = 0;
                }
                else if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }

        return;
    }
private:
    int isValid(int i, int j, int m, int n) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            return true;
        }
        return false;
    }

    int countNeigh(int i, int j, vector<vector<int>>& board, int m, int n) {
        int numNeigh = 0;

        if (isValid(i - 1, j - 1, m, n) && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == -2)) {
            numNeigh++;
        } 

        if (isValid(i - 1, j, m, n) && (board[i - 1][j] == 1 || board[i - 1][j] == -2)) {
            numNeigh++;
        }

        if (isValid(i - 1, j + 1, m, n) && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == -2)) {
            numNeigh++;
        }

        if (isValid(i, j - 1, m, n) && (board[i][j - 1] == 1 || board[i][j - 1] == -2)) {
            numNeigh++;
        }

        if (isValid(i, j + 1, m, n) && (board[i][j + 1] == 1 || board[i][j + 1] == -2)) {
            numNeigh++;
        }

        if (isValid(i + 1, j - 1, m, n) && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == -2)) {
            numNeigh++;
        }


        if (isValid(i + 1, j, m, n) && (board[i + 1][j] == 1 || board[i + 1][j] == -2)) {
            numNeigh++;
        }

        if (isValid(i + 1, j + 1, m, n) && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == -2)) {
            numNeigh++;
        }

        return numNeigh;
    }
};