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
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        int sum = 0;

        s.push({root, 0});

        while(!s.empty()) {
            auto [root, val] = s.top();
            s.pop();

            val = val*10 + root->val;

            if (root && !root->left && !root->right) {
                sum += val;
            }
            else {
                if (root->left) {
                    s.push({root->left, val});
                }
                if (root->right) {
                    s.push({root->right, val});
                }
            }
        }

        return sum;
    }
};
