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
 // Time complexity: O(N), Space complexity: O(N) Auxiliary Stack Space
class Solution {
public:
    int sumNumbers(TreeNode* root) {
       if (!root) {
           return 0;
       }
       
       long long int sum = 0;
       
       compSum(root, sum, 0);
       return sum; 
    }
private:
    void compSum(TreeNode* node, long long int& sum, int currSum) {
        if (node && !node->left && !node->right) {
            sum += currSum*10 + node->val;
        }
        if (!node) {
            return;
        }
        compSum(node->left, sum, currSum*10 + node->val);
        compSum(node->right, sum, currSum*10 + node->val);

    }
};
