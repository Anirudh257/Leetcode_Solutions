// Time complexity: O(MN), M = number of nodes in tree, N = number of nodes in subTree, 
// Space complexity: O(1) + Auxiliary stack space: O(M + N)  
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return subRoot == nullptr;
        }
        if (isIdentical(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool isIdentical(TreeNode* node1, TreeNode* node2) {
        if (!node1 || !node2) {
            return node2 == nullptr && node1 == nullptr;
        }

        if (node1->val != node2->val) {
            return false;
        }
        return node1->val == node2->val && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
    }
};
