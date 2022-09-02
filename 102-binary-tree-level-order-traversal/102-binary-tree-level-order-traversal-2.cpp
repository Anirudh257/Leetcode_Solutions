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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       // Time complexity: O(N), Space complexity: O(N) 
        if (!root) {
            return {};
        }
        
        vector<vector<int>> trav;
        queue<TreeNode*> queue;
        
        queue.push(root);
        
        while(!queue.empty()) {
            int qLen = queue.size();
            vector<int> lev;
            for (int i = 0; i < qLen; i++) {
                TreeNode* top = queue.front();
                queue.pop();
                if (!top) {
                    continue;
                }
                lev.push_back(top->val);
                
                if (top->left) {
                    queue.push(top->left);
                }
                if (top->right) {
                    queue.push(top->right);
                }
                
            }
            trav.push_back(lev);
        }
        
        return trav;
    }
};
