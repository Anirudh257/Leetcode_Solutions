class TrieNode {
public:
    TrieNode(bool b = false) {
        isWordEnd = b;
        memset(next, 0, sizeof(next));
    }    
    TrieNode* next[26];
    bool isWordEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }
    
    ~Trie() {
        clear(root);
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int ind = ch - 'a';
            if (curr->next[ind] == NULL) {
                curr->next[ind] = new TrieNode;
            }
            curr = curr->next[ind];
        }
        curr->isWordEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int ind = ch - 'a';
            if (curr->next[ind] == NULL) {
                return false;
            }
            curr = curr->next[ind];
        }
        return curr->isWordEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            int ind = ch - 'a';
            if (curr->next[ind] == NULL) {
                return false;
            }
            curr = curr->next[ind];
        }
        return true;
    }
private:
    TrieNode* root;
    
    void clear(TrieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root->next[i] != NULL) {
                clear(root->next[i]);
            }
        }
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
