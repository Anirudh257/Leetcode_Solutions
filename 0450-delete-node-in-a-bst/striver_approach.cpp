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

 // Time complexity: O(H), Space complexity: O(H)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return NULL;
        }
        if (root->val == key) {
            return helper(root);
        }
        TreeNode* cpRoot = root;

        while(root) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        return cpRoot;
    }
private:
    TreeNode* helper(TreeNode* node) {
        if (!node->left) {
            return node->right;
        }
        else if (!node->right) {
            return node->left;
        }

        // Go to the rightmost child of left and to its right, attach the righter child.
        TreeNode* rightChild = node->right;
        TreeNode* lastRight = findLastRight(node->left);
        lastRight->right = rightChild;
        return node->left;
    }

    TreeNode* findLastRight(TreeNode* node) {
        if (!node->right) {
            return node;
        }
        return findLastRight(node->right);
    }
};