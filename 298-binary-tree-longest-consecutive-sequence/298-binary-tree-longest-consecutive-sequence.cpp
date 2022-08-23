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
        int longStreak = 1;
        
        longStreak = max(compStreak(root, root->left, 1, longStreak), compStreak(root, root->right, 1, longStreak));
        
        
        return longStreak;
    }
private:
    int compStreak(TreeNode* prev, TreeNode* curr, int currStreak, int longStreak) {
        if (!curr) {
            return longStreak = max(longStreak, currStreak);
        }
        
        if (curr->val == prev->val + 1) {
            longStreak = max(currStreak + 1, longStreak);
            currStreak = max(compStreak(curr, curr->left, currStreak + 1, longStreak), compStreak(curr, curr->right, currStreak + 1, longStreak));
        }
        else {
            currStreak = max(compStreak(curr, curr->left, 1, longStreak), compStreak(curr, curr->right, 1, longStreak));

        }
        
        return longStreak = max(longStreak, currStreak);
    }
};