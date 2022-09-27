class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int size = word.size(), m = board.size(), n = board[0].size();
        
        if (size > m*n) {
            return false;
        }
        
        unordered_map<char, int> occ;
        
        for (auto &row : board) {
            for (auto &ch : row) {
                occ[ch]++;
            }
        }
        
        for (char ch : word) {
            occ[ch]--;
            if (occ[ch] < 0) {
                return false;
            }
        }
        
        // Reverse the string if longest suffix is longer than the longest prefix. 
        int left = word.find_first_not_of(word[0]);
        int right = size - word.find_last_not_of(word[size - 1]);
        
        // [["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"]]
        // "AAAAAAAAAAAAAAB" 
        // it changes word to "BAAAAAAAAAAAAAA"
        
        if (left > right) {
            reverse(begin(word), end(word));
        }
        
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
