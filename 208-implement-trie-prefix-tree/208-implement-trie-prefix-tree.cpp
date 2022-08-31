#define ALPHABET_SIZE 26

struct Node {
    Node* links[ALPHABET_SIZE];
    bool isWordEnd = false;
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void setEnd() {
        isWordEnd = true;
    }
    
    bool isEnd() {
        return isWordEnd;
    }
     
};

class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    
    void insert(string word) {
        Node* currNode = root;
        
        for (char ch : word) {
            if (!currNode->containsKey(ch)) {
                currNode->put(ch, new Node());
            }
            currNode = currNode->get(ch);
        }
        currNode->setEnd();
    }
    
    bool search(string word) {
        Node* currNode = root;
        
        for (char ch : word) {
            if (!currNode->containsKey(ch)) {
                return false;
            }
            currNode = currNode->get(ch);
        }
        return currNode->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* currNode = root;
        
        for (char ch : prefix) {       
            if (!currNode->containsKey(ch)) {
                return false;
            }
            currNode = currNode->get(ch);
        }
        return true;
    }
private:
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */