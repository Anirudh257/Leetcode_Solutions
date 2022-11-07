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


class cmp{
public:
    int operator() (const int &x, const int &y) {
        return x > y;
    }    
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, cmp> pq; 
        
        dfs(root, pq);
        
        while(!pq.empty()) {
            int ans = pq.top();
            pq.pop();
            
            if (k == 1) {
                return ans;
            }
            k--;
        }
        
        return 0;
        
    }
private:
    void dfs(TreeNode* root, priority_queue<int, vector<int>, cmp>& pq) {
        if (!root) {
            return;
        }
        dfs(root->left, pq);
        pq.push(root->val);
        dfs(root->right, pq);
    }
};