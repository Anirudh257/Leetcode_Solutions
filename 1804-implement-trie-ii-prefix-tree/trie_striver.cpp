#include<iostream>
#include<vector>

using namespace std;

#define ALPHABET_SIZE 26

// Reference: https://www.youtube.com/watch?v=K5pcpkEMCN0&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=2

/*
	insert - Time complexity: O(len(word)), Space complexity: O(len(word))

	countWordsEqualTo - Time complexity: O(len(word)), Space complexity: O(1)
	
	countWordsStartingWith - Time complexity: O(len(word)), Space complexity: O(1)

	erase - Time complexity: O(len(word)), Space complexity: O(1)
*/


struct TrieNode {
	TrieNode* links[ALPHABET_SIZE];
	int countWords = 0;
	int countPrefix = 0;

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
		countPrefix++;
	}

	void incEnd() {
		countWords++;
	}

	void delEnd() {
		countWords--;
	}

	void redPref() {
		countPrefix--;
	}

	int getNumWords() {
		return countWords;
	}

	int getNumPrefs() {
		return countPrefix;
	}

};

class Trie {
private:
	TrieNode* root;
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
		currNode->incEnd();
	}

	int countWordsEqualTo(string word) {
		TrieNode* currNode = root;

		for (char ch : word) {
			if (!currNode->containsKey(ch)) {
				return 0;
			}
			currNode = currNode->get(ch);
		}
		return currNode->getNumWords();
	}

	int countWordsStartingWith(string prefix) {
		TrieNode* currNode = root;

		for (char ch : prefix) {
			if (!currNode->containsKey(ch)) {
				return 0;
			}
			currNode = currNode->get(ch);
		}
		return currNode->getNumPrefs();
	}

	void erase(string word) {
		TrieNode* currNode = root;

		for (char ch : word) {
			if (!currNode->containsKey(ch)) {
				return;
			}
			currNode = currNode->get(ch);
			currNode->redPref();
		}		
		currNode->delEnd();
	}
};

int main() {

	Trie trie;

	int n = 9;

	/*
		1 = insert
		2 = countWordsEqualTo
		3 = countWordsStartingWith
		4 = erase
	*/

	vector<int> type = {1, 1, 2, 3, 4, 2, 3, 4, 3};
	vector<string> words = {"apple", "apple", "apple", "app", "apple", "apple", "app",
	 "apple", "app"};

	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(words[i]);
		}
		else if (type[i] == 2) {
			int res = trie.countWordsEqualTo(words[i]);
			cout << "Number of words in trie equal to " << words[i] << " are " << res << endl;
		}
		else if (type[i] == 3) {
			int res = trie.countWordsStartingWith(words[i]);
			cout << "Number of words in trie starting with " << words[i] << " are " << res << endl;			
		}
		else {
			trie.erase(words[i]);
			cout << "Word " << words[i] << " has been erased" << endl;
		}
	}
	return 0;
}
