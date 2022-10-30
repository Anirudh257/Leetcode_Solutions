#define ALPHALEN 26

class Word{
public:
    Word() {
        isWordEnd = false;
        memset(next, 0, sizeof(next));
    }
    Word* next[ALPHALEN];
    bool isWordEnd;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new Word(); 
    }
    
    void addWord(string word) {
        Word* curr = root;
        for (char ch : word) {
            int ind = ch - 'a';
            if (curr->next[ind] == nullptr) {
                curr->next[ind] = new Word;
            }
            curr = curr->next[ind];
        }
        curr->isWordEnd = true;
    }
    
    bool search(string word) {
        return search(word.c_str(), root);        
    }
private:
    Word* root;
    
    bool search(const char* word, Word* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node->next[word[i] - 'a'];
            }
            else {
                Word* temp = node;
                for (int j = 0; j < 26; j++) {
                    node = temp->next[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node->isWordEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */