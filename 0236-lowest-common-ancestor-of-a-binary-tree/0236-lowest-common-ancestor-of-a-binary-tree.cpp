/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        unordered_map<TreeNode*, TreeNode*> parMap;
        compPath(parMap, root, root->left);
        compPath(parMap, root, root->right);
        
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ = pathP;
        
        TreeNode* curr = p;
        
        while(curr != root) {
            pathP.push_back(curr);
            curr = parMap[curr];
        }
        
        curr = q;
        
        while(curr != root) {
            pathQ.push_back(curr);
            curr = parMap[curr];
        }
        pathP.push_back(root);
        pathQ.push_back(root);
        
        // for (auto &x : pathP) {
        //     cout << x->val << endl;
        // }
        // for (auto &x : pathQ) {
        //     cout << x->val << endl;
        // }        
        int pSize = pathP.size();
        int qSize = pathQ.size();
        TreeNode* lca;
        for (int i = pSize - 1, j = qSize - 1; i >= 0 && j >= 0; i--, j--) {
            if (pathP[i] == pathQ[j]) {
                lca = pathP[i];
            }
            else {
                break;
            }
        }
        
        
        return lca;
    }
private:
    void compPath(unordered_map<TreeNode*, TreeNode*>& parMap, TreeNode* curr, TreeNode* child) {
        
        if (!curr || !child) {
            return;
        }
        if (curr != child) {
            parMap[child] = curr;        
        }
        if (child->left) {
            compPath(parMap, child, child->left);        
        }
        if (child->right) {
            compPath(parMap, child, child->right);        
        }
        
        
    }
};