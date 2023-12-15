/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Time complexity: O(|V| + |E|) + O(|V|), Space complexity: O(|V|) 

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<bool>visited(MAX_NODES, false);
        unordered_map<int, TreeNode*> nodeMap;
        vector<int> dfsOrder;
        int numNodes = 0;
        
        int prevCnt = 0;
        dfs(visited, root, nodeMap, dfsOrder, numNodes);
        
        for (int i = numNodes - 1; i >= 0; i--) {
            int val = dfsOrder[i];
            TreeNode* node = nodeMap[val];
            node->val = val += prevCnt;
            prevCnt = val;
        }
        
        return root;
    }
private:
    int MAX_NODES = 101;
    
    void dfs(vector<bool>& visited, TreeNode* node, unordered_map<int, TreeNode*>& nodeMap, vector<int>& dfsOrder,int& numNodes) {
        int val = node->val;
        if (visited[val]) {
            return;
        }
        nodeMap[val] = node;
        
        numNodes += 1;
        visited[val] = true;
        
        if (node->left) {
            dfs(visited, node->left, nodeMap, dfsOrder, numNodes);        
        }
        dfsOrder.push_back(node->val);
        if (node->right) {
            dfs(visited, node->right, nodeMap, dfsOrder, numNodes);        
        }
        
        return;
    }
};