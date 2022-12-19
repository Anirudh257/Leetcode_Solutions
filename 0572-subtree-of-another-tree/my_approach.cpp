// Time complexity: O(N), Space complexity: O(1) + Auxiliary space: O(N), N = number of nodes

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
        findSubTree(root, subRoot);   
        return ans;    
    }
private:
    bool ans = false;
    bool findSubTree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            if (subRoot) {
                return false;
            }
            else {
                return true;
            }
        }
        bool left = false, right = false;
        if (root && subRoot && root->val == subRoot->val) {
            left = checkSame(root->left, subRoot->left);
            right = checkSame(root->right, subRoot->right);
            if (left && right) {
                ans = true;
                return true;
            }
            else {
                left = false, right = false;
                left = findSubTree(root->left, subRoot);
                right = findSubTree(root->right, subRoot);

                if (left || right) {
                    return true;
                }

            }
        }
        else {
            left = false, right = false;
            left = findSubTree(root->left, subRoot);
            right = findSubTree(root->right, subRoot);

            if (left || right) {
                return true;
            }
        }

        return false;
    }

    bool checkSame(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            if (!subRoot) {
                return true;
            }
            else {
                return false;
            }
        }
        if (root && subRoot && root->val == subRoot->val) {
            bool left = false, right = false;
            left = checkSame(root->left, subRoot->left);
            right = checkSame(root->right, subRoot->right);

            if (left && right) {
                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }
};
