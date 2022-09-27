class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        // Time complexity: O(mn4^(word.size())), Space complexity: O(mn)
        
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    if (searchWord(board, word, i, j, 0, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
private:
    bool searchWord(vector<vector<char>>& board, string word, int i, int j, int ind, int m, int n) { 
        if (ind == word.size()) {
            return true;
        }
        
        if (i < 0 || i >= m || j < 0 || j >= n || word[ind] != board[i][j]) {
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '#';
        
        bool leftAns = searchWord(board, word, i, j - 1, ind + 1, m, n);
        bool rightAns = searchWord(board, word, i, j + 1, ind + 1, m, n);
        bool upAns = searchWord(board, word, i - 1, j, ind + 1, m, n);
        bool downAns = searchWord(board, word, i + 1, j, ind + 1, m, n);
        
        board[i][j] = ch;
        
        return leftAns || rightAns || upAns || downAns;
        
    }
};
