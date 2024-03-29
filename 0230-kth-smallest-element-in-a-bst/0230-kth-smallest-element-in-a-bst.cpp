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
        vector<int> nums;
        inorder(nums, root);

        return nums[k - 1];
    }
private:
    void inorder(vector<int>& nums, TreeNode* node) {
        if (!node) {
            return;
        }
        inorder(nums, node->left);
        nums.push_back(node->val);
        inorder(nums, node->right);
    }
};
