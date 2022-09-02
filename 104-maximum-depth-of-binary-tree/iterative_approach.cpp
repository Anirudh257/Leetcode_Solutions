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
    int maxDepth(TreeNode* root) {
        
        // Time complexity: O(N), Space complexity: O(N)[Only max nodes at a level stored at a time and not entire stack.
        
        if (!root) {
            return 0;
        }
        int maxDepth = 0;
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 1});
        
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            
            TreeNode* node = top.first;
            int dep = top.second;
            
            maxDepth = max(dep, maxDepth);
            
            if (node->left) {
                q.push({node->left, dep + 1});
            }
                        
            if (node->right) {
                q.push({node->right, dep + 1});
            }
            
        }
        
        
        return maxDepth;
    }
};
