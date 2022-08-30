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
        TreeNode* low = NULL;
        TreeNode* high = NULL;
        
        update(low, high, root);
        
        while(!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            
            low = lowLim.top();
            lowLim.pop();
            
            high = highLim.top();
            highLim.pop();
            
            if (!curr) {
                continue;
            }
            if (low != NULL && curr->val <= low->val) {
                return false;
            }
            
            if (high != NULL && curr->val >= high->val) {
                return false;
            }
            update(low, curr, curr->left);
            update(curr, high, curr->right);
            
            
        }
        
        return true;
    }
private:
    stack<TreeNode*> stk, lowLim, highLim;
    
    void update(TreeNode* low, TreeNode* high, TreeNode* curr) {
        stk.push(curr);
        lowLim.push(low);
        highLim.push(high);
    }
};
