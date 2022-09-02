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
        vector<vector<int>> trav;
        
        queue<pair<TreeNode*, int>> q;
        
        if (!root) {
            return {};
        }
        
        if (!root->left && !root->right) {
            return {{root->val}};
        }
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            
            TreeNode* node = top.first;
            
            int val = node->val;
            int ind = top.second;
            
            if (trav.size() == 0) {
                trav = {{val}};
            }
            else {
                if (trav.size() == ind) {
                    vector<int> newLev = {val};
                    trav.push_back(newLev);
                }
                else if (trav.size() > ind) {
                    trav[ind].push_back(val);
                }
            }
            
            if (node->left) {
                q.push({node->left, ind + 1});
            }
            
            if (node->right) {
                q.push({node->right, ind + 1});
            }

        }
        
        
        return trav;
    }
};