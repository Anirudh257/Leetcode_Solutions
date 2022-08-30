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
    // Time complexity: O(n), Space complexity: Auxiliary space: O(n), n = no. of nodes.
    bool isValidBST(TreeNode* root) {
        if (!root || !root->left && !root->right) {
            return true;
        }
        
        
        return checkVal(root, nullptr, nullptr);
    }
private:
    bool checkVal(TreeNode* curr, TreeNode* low, TreeNode* high) {
        if (!curr) {
            return true;
        }
        
        if ((low != nullptr && curr->val <= low->val) || (high != nullptr && curr->val >= high->val)) {
            return false;
        }        

        
        return checkVal(curr->left, low, curr) && checkVal(curr->right, curr, high);
        
        
    }
};