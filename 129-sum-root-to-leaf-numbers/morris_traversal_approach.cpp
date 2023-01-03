// Time complexity: O(N), Space complexity: O(1)
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
    int sumNumbers(TreeNode* root) {
        int sum = 0, depth = 0, currSum = 0;

        while(root) {
            if (root->left) {
                auto pre = root->left;
                depth = 1;
                while(pre->right && pre->right != root) {
                    pre = pre->right;
                    depth++;
                }
                // Make a threaded binary tree if not existing already
                if (!pre->right) {
                    pre->right = root;
                    currSum = currSum*10 + root->val;
                    root = root->left;
                }
                // Remove the existing link to the root node from rightmost node
                else {
                    pre->right = NULL;
                    if (!pre->left) {
                        sum += currSum;
                    }
                    currSum /= pow(10, depth);
                    root = root->right;
                }
            }
            else {
                currSum = currSum*10 + root->val;
                if (!root->right) {
                    sum += currSum;
                }
                root = root->right;
            }
        }


        return sum;
    }
};
