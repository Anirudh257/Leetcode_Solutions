class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int wordLen = word.length();
        
        // Time complexity: O(m*n*dfs(len(word))), Space complexity: O(m*n)
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    bool ans = checkWord(board, word, i, j, m, n, 0);
                    if (ans) {
                        return true;
                    }
                    // visited[i][j] = false;
                }
            }
        }
        
        return false;
    }
private:
    bool checkWord(vector<vector<char>>& board, string word, int i, int j, int m, int n, int ind) {
        if (ind  == word.size() - 1) {
            if (word[ind] == board[i][j]) {
                return true;
            }
        }
        
        if (word[ind] != board[i][j]) {
            return false;
        }
        
        char reqCh = board[i][j];
        board[i][j] = '*';        
        
        bool leftAns = false;
        bool rightAns = false;
        bool upAns = false;
        bool downAns = false;
        
        if (valid(i - 1, j, m, n)) {
            upAns = checkWord(board, word, i - 1, j, m, n, ind + 1);
            // visited[i - 1][j] = false;
        }
        
        if (valid(i + 1, j, m, n)) {
            downAns = checkWord(board, word, i + 1, j, m, n, ind + 1);
            // visited[i + 1][j] = false;
        }

        if (valid(i, j - 1, m, n)) {
            leftAns = checkWord(board, word, i, j - 1, m, n, ind + 1);
            // visited[i][j - 1] = false;
        }
        
        if (valid(i, j + 1, m, n)) {
            rightAns = checkWord(board, word, i, j + 1, m, n, ind + 1);
            // visited[i][j + 1] = false;
        }
        
        board[i][j] = reqCh;
        return leftAns || rightAns || upAns || downAns;
    }
private:
    bool valid(int i, int j, int m, int n) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            return true;
        }
        return false;
    }
};