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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int len = inorder.size();
        
        for (int i = 0; i < len; i++) {
            inMap[inorder[i]] = i;
        } 
        
        return buildTree(inMap, 0, len - 1, inorder, preorder, 0, len - 1);
    }
private:
    TreeNode* buildTree(unordered_map<int, int>& inMap, int inSt, int inEnd, vector<int>& inorder, vector<int>& preorder, int preSt, int preEnd) {
        if (inSt > inEnd || preSt > preEnd) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[preSt]);
        int inRoot = inMap[node->val];
        int numLeft = inRoot - inSt;
        
        node->left = buildTree(inMap, inSt, inRoot - 1, inorder, preorder, preSt + 1, preSt + numLeft);
        node->right = buildTree(inMap, inRoot + 1, inEnd, inorder, preorder, preSt + numLeft + 1, preEnd);
        
        return node;
    }
};