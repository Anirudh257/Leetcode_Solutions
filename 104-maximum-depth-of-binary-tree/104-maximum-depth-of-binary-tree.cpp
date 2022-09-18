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
    // Time complexity: O(N), Space complexity: O(N)
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
       return max(compDepth(root->left, 1), compDepth(root->right, 1)); 
    }
private:
    int compDepth(TreeNode* node, int depth) {
        if (!node) {
            return depth;
        }
       return max(compDepth(node->left, depth + 1), compDepth(node->right, depth + 1)); 
        
    }
};