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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // Time complexity: O(N), Space complexity: O(N)
        queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);
        
        while(!queue.empty()) {
            TreeNode* top1 = queue.front();
            queue.pop();
            TreeNode* top2 = queue.front();
            queue.pop();
            
            if (!top1 && !top2) {
                continue;
            }
            if (!top1 || !top2) {
                return false;
            }
            
            if (top1->val != top2->val) {
                return false;
            }
            
            queue.push(top1->left);
            queue.push(top2->left);
            queue.push(top1->right);
            queue.push(top2->right);
            
            
        }
        return true;
    }
};
