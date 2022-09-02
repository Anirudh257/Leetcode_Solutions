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
        perfTrav(root, 0);
        
        return levTrav;
    }
private:
    vector<vector<int>> levTrav;
    
    void perfTrav(TreeNode* node, int lev) {
        if (!node) {
            return;
        }
        if (levTrav.size() == lev) {
            levTrav.push_back({});
        }
        
        levTrav[lev].push_back(node->val);
        
        perfTrav(node->left, lev + 1);
        perfTrav(node->right, lev + 1);
    
    }
    
};
