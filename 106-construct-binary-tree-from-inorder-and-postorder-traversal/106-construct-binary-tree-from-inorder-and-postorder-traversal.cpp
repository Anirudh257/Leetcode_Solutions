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
    
    // Time complexity: O(N), Space complexity: O(N)
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        int len = inorder.size();
        
        for (int i = 0; i < len; i++) {
            inMap[inorder[i]] = i;
        }
        
        return buildTree(inorder, postorder, inMap, 0, len - 1, 0, len - 1);
    }
private:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inMap, int inSt, int inEnd, int poSt, int poEnd) {
      if (inSt > inEnd || poSt > poEnd) {
        return NULL;
      }
      int val = postorder[poEnd];
      TreeNode* node = new TreeNode(val);
      int inRoot = inMap[val];
      int numLeft = inRoot - inSt;
      
      node->left = buildTree(inorder, postorder, inMap, inSt, inRoot - 1, poSt, poSt + numLeft - 1);
      node->right = buildTree(inorder, postorder, inMap, inRoot + 1, inEnd, poSt + numLeft, poEnd - 1);
      
      return node;
  }
};