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
    int longestConsecutive(TreeNode* root) {
        return compStreak(root, nullptr, 0);
    }
private:
    int compStreak(TreeNode* curr, TreeNode* prev, int currLen) {
        if (!curr) {
            return currLen;
        }
        currLen = (prev && curr->val == prev->val + 1) ? currLen + 1 : 1;
        return max(currLen, max(compStreak(curr->left, curr, currLen), compStreak(curr->right, curr, currLen)));
    }
};