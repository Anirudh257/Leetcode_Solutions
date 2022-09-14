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
        
        return buildTree(preorder, inorder, 0, len - 1, 0, len - 1, inMap);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int inSt, int inEnd, int pSt, int pEnd, unordered_map<int, int>& inMap) {    
        if (inSt > inEnd || pSt > pEnd) {
            return NULL;
        }
        int val = preorder[pSt];
        TreeNode* node = new TreeNode(val);
        int inRoot = inMap[val];
        int numLeft = inRoot - inSt;
        
        node->left = buildTree(preorder, inorder, inSt, inRoot - 1, pSt + 1, pSt + numLeft, inMap);
            
        node->right = buildTree(preorder, inorder, inRoot + 1, inEnd, pSt + numLeft + 1, pEnd, inMap);
        
        return node;
    }
};