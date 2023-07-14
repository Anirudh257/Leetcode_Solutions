/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Time complexity: O(H), Space complexity: O(1)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;

        while(root) {
            if (root->val > p->val) {
                successor = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return successor;
    }
};