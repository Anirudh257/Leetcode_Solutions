// Time complexity: O(N), Space complexity: O(N)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        unordered_map<Node*, Node*> oldToNew;

        return clone(node, oldToNew);
    }
private:
    Node* clone(Node* node, unordered_map<Node*, Node*>& oldToNew) {
        if (oldToNew.find(node) != oldToNew.end()) {
            return oldToNew[node];
        }
        Node* newNode = new Node(node->val);
        oldToNew[node] = newNode;

        for(auto &nei : node->neighbors) {
            newNode->neighbors.push_back(clone(nei, oldToNew));
        }

        return newNode;
    }
};
