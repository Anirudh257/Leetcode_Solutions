// Time complexity: O(N), Space complexity: O(1) + Auxiliary stack space: O(N)
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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        countUnivalRecur(root, count);
        return count;
    }
private:
    bool countUnivalRecur(TreeNode* node, int& count) {
        if (!node) {
            return true;
        }
        bool left = countUnivalRecur(node->left, count);
        bool right = countUnivalRecur(node->right, count);

        if (left && right && ((node->left == NULL) || node->left->val == node->val) &&
        ((node->right == NULL) || (node->right->val == node->val))) {
            count++;
            return true;
        }
        return false;

    }
};
