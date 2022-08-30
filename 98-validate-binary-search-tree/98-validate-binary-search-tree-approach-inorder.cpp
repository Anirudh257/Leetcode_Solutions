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
    // Time complexity: O(N), Space complexity: O(N)
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return checkInorder(root);
    }
private:
    TreeNode* prev;
    
    bool checkInorder(TreeNode* curr) {
        if (!curr) {
            return true;
        }
        
        if (!checkInorder(curr->left)) {
            return false;
        }
        
        if (prev != NULL && prev->val >= curr->val) {
            return false;
        }
        
        prev = curr;
        
        return checkInorder(curr->right);
        
    }
};
