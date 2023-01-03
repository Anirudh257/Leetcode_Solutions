// Time complexity: O(N), Space complexity: Auxiliary Stack Space: O(N)
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
      return checkPath(root, targetSum);
    }
private:
    bool checkPath(TreeNode* node, int targetSum) {
        if (!node) {
            return 0;
        }

        if (!node->left && !node->right) {
            targetSum -= node->val;
            return targetSum == 0;
        }
        bool leftSum = checkPath(node->left, targetSum - node->val, ans);
        bool rightSum = checkPath(node->right, targetSum - node->val, ans);

        return leftSum || rightSum;
    }
};
