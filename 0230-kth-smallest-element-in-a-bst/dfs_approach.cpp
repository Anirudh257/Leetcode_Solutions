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
// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
private:
    int dfs(TreeNode* node, int& k) {
        if (!node) {
            return INT_MIN;
        }
        // Go till the leftmost node is reached.
        int left = dfs(node->left, k);
        
        if (k == 0) {
            return left;
        }
        else if (k == 1) {
            k--;
            return node->val;
        }
        else {
            k--;
            int right = dfs(node->right, k);
            if (k == 0) {
                return right;
            }
            else {
                return INT_MIN;
            }
        }
    }
};
