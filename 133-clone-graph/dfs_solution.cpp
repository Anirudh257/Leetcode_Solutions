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
        // Time complexity: O(V + E), Space complexity: O(V)
        if (!node) {
            return NULL;
        }   
        
        if ((node->neighbors).size() == 0) {
            Node* copy = new Node(node->val);
            return copy;
        }
        unordered_map<Node*, Node*> origCopy;
        return cloneDFS(node, origCopy);
    }
private:
    Node* cloneDFS(Node* node, unordered_map<Node*, Node*>& origCopy) {
        Node* copy = new Node(node->val);
        origCopy[node] = copy;
        vector<Node* > neighbors;
        
        for (auto it : node->neighbors) {
            if (origCopy.count(it)) {
                neighbors.push_back(origCopy[it]);
            }
            else {
                neighbors.push_back(cloneDFS(it, origCopy));
            }
        }
        copy->neighbors = neighbors;
        return copy;
    }
};
