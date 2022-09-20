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
    // Time complexity: O(V + E), Space complexity: O(V)
    Node* cloneGraph(Node* node) {
        
        // if ()
        // if (node)
        if (!node) {
            // cout << "Here" << endl;
            // Node* newGraph;
            return NULL;
        }
        
        
        int initVal = node->val;
        Node* newGraph = new Node(initVal);
        
        if (initVal == 0) {
            return newGraph;
        } 
        
        unordered_map<int, Node*> valOrigNode;
        unordered_map<int, Node*> valNewNode;
        
        // visited[initVal] = newGraph;
        
        unordered_map<int, bool> done;
        
        perfDFS(node, valOrigNode, valNewNode);
        
        // for (int i = 0; i < node->neighbors.size(); i++) {
        //     int val = (node->neighbors[i])->val;
        //     Node* newNode = new Node(val);
        //     (newGraph->neighbors).push_back(newNode);
        // }
        
        // cout << newGraph->val << endl;
        
        // for (auto &x : valOrigNode) {
        //     cout << x.first << " ";
        //     for (auto &y: (x.second)->neighbors) {
        //         cout << y->val << " ";
        //     }
        //     cout << endl;
        // }
        
        for (auto &x : valOrigNode) {
            int val = x.first;
            Node* curr = x.second;
            
            
            // cout << val << endl;
            
            if (!done[val]) {
                Node* newNode = valNewNode[val];
                
                if (val == initVal) {
                    newGraph = newNode;
                }
                
                // if (val == initVal) {
                //     newNode = newGraph;
                // }
                // else {
                //     newNode = visited[val];                
                // }
                vector<Node*> neigh = curr->neighbors;
                
                vector<Node*> newNeighs;
                
                for (auto &y : neigh) {
                    Node* newNeg = valNewNode[y->val];
                    newNeighs.push_back(newNeg);
                }
                newNode->neighbors = newNeighs;
                
                done[val] = true;
                
            }
        }
        
        
        
        // cout << newGraph->val << endl;
        // perfDFS(newGraph, visited);
        
        
        return newGraph;
    }
private:
    
    void perfDFS(Node* node, unordered_map<int, Node*>& valOrigNode, unordered_map<int, Node*>& valNewNode) {
        if (valNewNode.count(node->val)) {
            return;
        }
        // cout << node->val;
        Node* copy = new Node(node->val);
        valNewNode[node->val] = copy;
        valOrigNode[node->val] = node;
            
        for (auto &neigh: node->neighbors) {
            perfDFS(neigh, valOrigNode, valNewNode); 
        }
    }
};