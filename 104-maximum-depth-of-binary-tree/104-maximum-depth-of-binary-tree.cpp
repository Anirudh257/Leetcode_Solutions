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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(compDepth(root->left, 1), compDepth(root->right, 1));
    }
    
    // f(9, 1) -> 2
    // f(20, 1) -> f(15, 2) -> NULL
private:
    int compDepth(TreeNode* node, int lev) {
        if (!node) {
            return lev;
        }
        return max(compDepth(node->left, lev + 1), compDepth(node->right, lev + 1));
    }
};