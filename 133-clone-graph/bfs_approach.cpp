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
        
        unordered_map<Node*, Node*> origCopy;
        Node* newNode = new Node(node->val);
        origCopy[node] = newNode;
        queue<Node*> q;
        
        q.push(node);
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            for (auto neigh : front->neighbors) {
                if (origCopy.find(neigh) == origCopy.end()) {
                    Node* copyNode = new Node(neigh->val);
                    origCopy[neigh] = copyNode;
                    q.push(neigh);
                }
                origCopy[front]->neighbors.push_back(origCopy[neigh]);
            }
            
        }
        
        return origCopy[node];
    }
};
