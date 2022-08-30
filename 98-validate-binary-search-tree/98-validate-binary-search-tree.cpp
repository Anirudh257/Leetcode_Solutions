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
    bool isValidBST(TreeNode* root) {
        if (!root || !root->left && !root->right) {
            return true;
        }
        
        
        return checkVal(root->left, LONG_MIN, (long)root->val, root) && checkVal(root->right, (long)root->val, LONG_MAX, root);
    }
private:
    bool checkVal(TreeNode* curr, long minLim, long maxLim, TreeNode* par) {
        if (!curr) {
            return true;
        }

        if (minLim >= curr->val || curr->val >= maxLim) {
            return false;
        }            

        
        return checkVal(curr->left, minLim ,curr->val, curr) && checkVal(curr->right, curr->val, maxLim, curr);
        
        
    }
};