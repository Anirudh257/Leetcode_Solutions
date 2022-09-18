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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        long long int width = 0;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            long long int mmin = q.front().second;
            long long int first, last;
            int size = q.size();
                
            for (int i = 0; i < size; i++) {
                long long int curId = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0) {
                    first = curId;
                }
                if (i == size - 1) {
                    last = curId;
                }
                
                if (node->left) {
                    q.push({node->left, 2*curId + 1});
                }
                if (node->right) {
                    q.push({node->right, 2*curId + 2});
                }
            }
            width = max(width, last - first + 1);
        }
        
        return width;
    }
};