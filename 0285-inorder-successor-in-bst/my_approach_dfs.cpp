/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // Tree complexity: O(n) + O(logn) for search, n = total number of nodes, Space complexity: O(n) + Auxiliary stack space: O(n)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        unordered_map<int, TreeNode*> nodeMap;
        vector<int> inorder;

        compInorderDFS(root, p, inorder, nodeMap);

        int ind = lower_bound(inorder.begin(), inorder.end(), p->val) - inorder.begin();

        if (ind < inorder.size() - 1) {
            return nodeMap[inorder[ind + 1]];
        }

        return nullptr;
    }
private:
    void compInorderDFS(TreeNode* node, TreeNode* p, vector<int>& inorder, unordered_map<int, TreeNode*>& nodeMap) {
        if (node) {
            
            if (node->left) {
                compInorderDFS(node->left, p, inorder, nodeMap);
            }

            inorder.push_back(node->val);
            nodeMap[node->val] = node;

            if (node->right) {
                compInorderDFS(node->right, p, inorder, nodeMap);
            }            

        }
    }
};