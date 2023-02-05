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
    // Time complexity: O(H), Space complexity: O(H), H = N for skewed tree and logN for balanced tree
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            TreeNode* newRoot = new TreeNode(val);
            return newRoot;
        }

        perfInsertion(root, val);
        return root;
    }
private:
    void perfInsertion(TreeNode* node, int val) {
        if (!node) {
            return;
        }
        if (node && !node->right && val > node->val) {
            TreeNode* newNode = new TreeNode(val);
            node->right = newNode;
            return;
        }

        if (node && !node->left && val < node->val) {
            TreeNode* newNode = new TreeNode(val);
            node->left = newNode;
            return;

        }

        if (node && val > node->val) {
            perfInsertion(node->right, val);
        }
        else {
            perfInsertion(node->left, val);
        }
    }
};
