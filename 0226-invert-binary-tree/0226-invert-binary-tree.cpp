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
    TreeNode* invertTree(TreeNode* root) {
        if (!root || !root->left && !root->right) {
            return root;
        }
        invertChild(root, root->left, root->right);
        return root;
    }
private:
    TreeNode* invertChild(TreeNode* parent, TreeNode* leftChild, TreeNode* rightChild) {
        if (!leftChild && !rightChild) {
            return parent;
        }
        if (!leftChild) {
            parent->right = NULL;
            parent->left = invertChild(rightChild, rightChild->left, rightChild->right);
        }
        else if (!rightChild) {
            parent->left = NULL;
            parent->right = invertChild(leftChild, leftChild->left, leftChild->right);
        }
        else {
            parent->left = invertChild(rightChild, rightChild->left, rightChild->right);
            parent->right = invertChild(leftChild, leftChild->left, leftChild->right);
        }

        return parent;

    }
};