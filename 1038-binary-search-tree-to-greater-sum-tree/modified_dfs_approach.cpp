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
 // Time complexity: O(|V| + |E|), Space complexity: Auxiliary Space of O(|V|)
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        // Keep going right till it is not possible and return the sum obtained. All nodes on the right >= current node.
        if (root->right) {
            bstToGst(root->right);
        }
        prevVal = root->val = prevVal + root->val;
        if (root->left) {
            bstToGst(root->left);
        }
        return root;
    }
private:
    int prevVal = 0;
};