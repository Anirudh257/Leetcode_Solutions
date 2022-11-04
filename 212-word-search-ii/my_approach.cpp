#define ALPHALEN 26

// Time complexity: O(NM*NM) for checking each element in the board, O(len(word)*num(words)) for insertion in trie.

// Space complexity: O(NM*NM) for visited boolean array, O(len(word)*num(words)) for maintaining Trie

class TrieNode {
public:
    TrieNode* child[ALPHALEN];
    int numWordEnds;
    string word;
        
    TrieNode() {
        numWordEnds = 0;
        word = "";
        for (int i = 0; i < ALPHALEN; i++) {
            child[i] = NULL;
        }
    }    
};

class Solution {
public:
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int ind = c - 'a';
            if (curr->child[ind] == NULL) {
                curr->child[ind] = new TrieNode();
            }
            curr = curr->child[ind];
        }
        curr->word = word;
        curr->numWordEnds++;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> presWords;
        root = new TrieNode();

        // Add the words in the trie
        for (auto &x : words) {
            insert(x);
        }
        
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                searchInd(i, j, m, n, board, root, presWords, visited);
            }
        }
        
        
        return presWords;
    }
private:
    TrieNode* root;
    
    void searchInd(int i, int j, int m, int n, vector<vector<char>>& board, TrieNode* curr, vector<string>& presWords, vector<vector<bool>>& visited) {
        char ch = board[i][j];
        int ind = ch - 'a';
        
        if (visited[i][j] || curr->child[ind] == NULL) {
            return;
        }
        
        curr = curr->child[ind];
        
        if (curr->numWordEnds > 0) {
            presWords.push_back(curr->word);
            curr->numWordEnds--;
        }
        
        visited[i][j] = true;
        
        if (valid(i - 1, j, m, n)) {
            searchInd(i - 1, j, m, n, board, curr, presWords, visited); 
        }
        if (valid(i + 1, j, m, n)) {
            searchInd(i + 1, j, m, n, board, curr, presWords, visited); 
        }
        if (valid(i, j - 1, m, n)) {
            searchInd(i, j - 1, m, n, board, curr, presWords, visited); 
        }
        if (valid(i, j + 1, m, n)) {
            searchInd(i, j + 1, m, n, board, curr, presWords, visited); 
        }        
        
        visited[i][j] = false;
            
        return;
    }

    bool valid(int i, int j, int m, int n) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            return true;
        }
        return false;
    }
    
};
