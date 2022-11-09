/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time complexity: O(N), Space complexity: O(N), N = number of nodes of a tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        compPath(root, p, pathP);
        compPath(root, q, pathQ);
        
//         for (auto &x : pathP) {
//             cout << x->val << endl;
//         }
        
//         for (auto &x : pathQ) {
//             cout << x->val << endl;
//         }        
        
        TreeNode* lca = root;
        
        
        for(int i = 0; i < min(pathP.size(), pathQ.size()); i++) {
            int pVal = pathP[i]->val;
            int qVal = pathQ[i]->val;
            
            
            
            if (pVal == qVal) {
                lca = pathP[i];
            }
            else {
                return lca;
            }
            
        }
        
        
        
        return lca;
    }
private:
    void compPath(TreeNode* curr, TreeNode* node, vector<TreeNode*>& path) {
        if (curr == node) {
            path.push_back(curr);
            
            return;
        }
        
        path.push_back(curr);
        
        if (node->val < curr->val) {
            // path.push_back(node);
            compPath(curr->left, node, path);
        }
        else {
            // path.push_back(node);
            compPath(curr->right, node, path);
        }
        return;
    }
};