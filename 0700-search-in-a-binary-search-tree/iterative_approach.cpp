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
        while(root && val != root->val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};