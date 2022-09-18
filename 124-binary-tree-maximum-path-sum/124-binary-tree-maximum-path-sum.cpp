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
    int maxPathSum(TreeNode* root) {
        // Time complexity: O(N), Space complexity: Auxiliary Space: O(N)
        int maxPath = INT_MIN;
        compPath(root, maxPath);
        return maxPath;
    }
private:
    int compPath(TreeNode* node, int& maxPath) {
        if (!node) {
            return 0;
        }
        int left = max(0, compPath(node->left, maxPath));
        int right = max(0, compPath(node->right, maxPath));
        maxPath = max(maxPath, left + right + node->val);
        
        return node->val + max(left, right);
    }
};