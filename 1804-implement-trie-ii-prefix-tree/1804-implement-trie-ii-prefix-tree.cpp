#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode* links[ALPHABET_SIZE];
    int countWords = 0;
    int countPref = 0;
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }
    
    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }
    
    void incPref() {
        countPref++;
    }
    
    void incWord() {
        countWords++;
    }
    
    int getWordCnt() {
        return countWords;
    }
    
    int getPrefCnt() {
        return countPref;
    }
    
    void decPrefCnt() {
        countPref--;
    }
    
    void decWordCnt() {
        countWords--;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* currNode = root;
        
        for (char ch : word) {
            if (!currNode->containsKey(ch)) {
                currNode->put(ch, new TrieNode());
            }
            currNode = currNode->get(ch);
            currNode->incPref();
        }
        currNode->incWord();
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* currNode = root;
        
        for (char ch : word) {
            if (!currNode->containsKey(ch)) {
                return 0;
            }
            currNode = currNode->get(ch);
        }
        return currNode->getWordCnt();        
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* currNode = root;
        
        for (char ch : prefix) {
            if (!currNode->containsKey(ch)) {
                return 0;
            }
            currNode = currNode->get(ch);
        }
        return currNode->getPrefCnt();        
    }
    
    void erase(string word) {
        TrieNode* currNode = root;
        
        for (char ch : word) {
            if (!currNode->containsKey(ch)) {
                return;
            }
            currNode = currNode->get(ch);
            currNode->decPrefCnt();
        }
        return currNode->decWordCnt();        
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */