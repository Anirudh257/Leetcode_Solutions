/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time complexity: O(N), Space complexity: O(1), N = number of nodes
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);
        TreeNode* curr = root;
        
        while(curr) {
            if (curr->val > large) {
                curr = curr->left;
            }
            else if (curr->val < small) {
                curr = curr->right;
            }
            else {
                return curr;
            }
        }
        return curr;
    }
};
