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
 // Time complexity: O(N), Space complexity: Auxiliary stack space: O(N)
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        compRec(root, maxSum);
        return maxSum;
    }
private:
    int compRec(TreeNode* node, int& maxSum) {
        if (!node) {
            return 0;
        }
        // Compute assuming split is allowed at a node
        int leftSum = compRec(node->left, maxSum);
        int rightSum = compRec(node->right, maxSum);
        leftSum = max(0, leftSum);
        rightSum = max(0, rightSum);

        maxSum = max(maxSum, leftSum + rightSum + node->val);

        // Returning value assuming no split is allowed
        return node->val + max(leftSum, rightSum);
    }
};
