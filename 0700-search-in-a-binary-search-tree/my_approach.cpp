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

 // Time complexity: O(log N), Space complexity: O(H), H = height of the tree
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) {
            return NULL;
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        else if (root->val < val) {
            return searchBST(root->right, val);
        }
        return root;
    }
};