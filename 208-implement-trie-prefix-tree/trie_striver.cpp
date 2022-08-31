#include<iostream>
#include<vector>
using namespace std;

#define ALPHABET_SIZE 26

// Reference: https://www.youtube.com/watch?v=dBGUmUQhjaM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp

/*
	insert - Time complexity : O(len(word)), Space complexity : O(len(word))

	search - Time complexity: O(len(word)), Space complexity: O(1)

	startsWith - Time complexity: O(len(word)), Space complexity: O(1)

*/

struct Node {
	
	// Reference node from 1 node to other 26 characters of the alphabet.
	Node* links[ALPHABET_SIZE]; 

	bool isEndOfWord = false; // True if word has ended.

	//checks if the reference trie is present or not
	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	//creating reference trie
	void put(char ch, Node* node) {
		links[ch - 'a'] = node;
	}

	//to get the next node for traversal
	Node* get(char ch) {
		return links[ch - 'a'];
	}

	//setting flag to true at the end of the word
	void setEnd() {
		isEndOfWord = true;
	}

	//checking if the word is completed or not
	bool isEnd() {
		return isEndOfWord;
	}
};

class Trie {
public:
	Trie() {
		root = new Node(); // Initializing the Data Structure.
	}

	// Insert word into trie
	void insert(string word) {
		Node* currNode = root;

		for (char ch : word) {

			// check if node pointing to a character exists, if not, create a new pointer.
			if (!currNode->containsKey(ch)) {
				currNode->put(ch, new Node());
			} 

			// Move to a new trie.
			currNode = currNode->get(ch);
		}

		// Reached last character, change endOfWord = true.
		currNode->setEnd();
	}

	// Search if a word exists in trie.
	bool search(string word) {
		Node* currNode = root;

		for (char ch : word) {

			// check if node pointing to a character exists, if not return false
			if (!currNode->containsKey(ch)) {
				return false;
			}

			// Move to a new trie.
			currNode = currNode->get(ch);
		}

		// Reached last character, return if the word exists
		return currNode->isEnd();
	}

	bool startsWith(string prefix) {
		Node* currNode = root;

		for (char ch : prefix) {

			// check if node pointing to a character exists, if not return false
			if (!currNode->containsKey(ch)) {
				return false;
			}

			// move to the next trie
			currNode = currNode->get(ch);
		}

		// prefix exists and hence return true.
		return true;

	}

private:
	Node* root;
};

int main() {
	Trie trie;

	int n = 5;

	/*
		1 = insert
		2 = search
		3 = startsWith
	*/

	vector<int> type = {1, 1, 2, 3, 2};
	vector<string> words = {"hello", "help", "help", "hel", "hel"};

	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(words[i]);
		}
		else if (type[i] == 2) {
			bool ans = trie.search(words[i]);
			if (ans) {
				cout << words[i] << " is present" << endl;
			}
			else {
				cout << words[i] << " is absent" << endl;
			}
		}
		else {
			bool ans = trie.startsWith(words[i]);
			if (ans) {
				cout << "prefix starting with " << words[i] << " is present" << endl;
			}
			else {
				cout << "prefix starting with " << words[i] << " is absent" << endl;
			}
		}
	}

	return 0;
}
