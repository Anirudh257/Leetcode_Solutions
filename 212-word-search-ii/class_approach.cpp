#define ALPHALEN 26
// Time complexity: O(mn*4*3^(l - 2) + S), m = number of rows, n =#cols, l = len(word)
// S = total sum of length of all words.
// Space complexity: O(S)
class TrieNode {
public:
    bool isWordEnd;
    TrieNode* children[ALPHALEN];

    TrieNode() {
        isWordEnd = false;
        for (int i = 0; i < ALPHALEN; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* getRoot() {
        return root;
    }

    Trie(vector<string>& words) {
        root = new TrieNode();
        for (auto &x : words) {
            addWord(x);
        }
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int ind = ch - 'a';
            if (curr->children[ind] == NULL) {
                curr->children[ind] = new TrieNode();
            }
            curr = curr->children[ind];
        }
        curr->isWordEnd = true;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Using trie to reduce the number of checks for each word, if the word exists
        // in the trie and is found while traversing the 2 loops, we add to our set(to
        // avoid duplicate entries)
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        vector<string> wordsFound;
        unordered_set<string> wordsFoundSet;
        int m = board.size(), n = board[0].size();

        vector<vector<char>> boardCp = board;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                searchWords(boardCp, words, "", i, j, wordsFoundSet, root);
            }
        }

        for (auto &x : wordsFoundSet) {
            wordsFound.push_back(x);
        }

        return wordsFound;
    }
private:
    void searchWords(vector<vector<char>>& board, vector<string>& words, string word, int i, int j, unordered_set<string>& wordsFoundSet, TrieNode* curr) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == ' ') {
            return;
        }

        char ch = board[i][j];
        int ind = ch - 'a';

        if (curr->children[ind] != NULL) {
            board[i][j] = ' ';
            word += ch;

            curr = curr->children[ind];
            if (curr->isWordEnd) {
                wordsFoundSet.insert(word);
            }


            searchWords(board, words, word, i, j - 1, wordsFoundSet, curr);
            searchWords(board, words, word, i, j + 1, wordsFoundSet, curr);
            searchWords(board, words, word, i - 1, j, wordsFoundSet, curr);
            searchWords(board, words, word, i + 1, j, wordsFoundSet, curr);

            board[i][j] = ch;
        }

        return;
    }
};