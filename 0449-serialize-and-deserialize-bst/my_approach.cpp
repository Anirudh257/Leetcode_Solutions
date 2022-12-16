// Time complexity: O(N), Space complexity: O(N), where N = number of nodes 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        perfSerial(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        queue<int> q;
        string s;

        while(iss >> s) {
            q.push(stoi(s));
        }

        return deserial(q, INT_MIN, INT_MAX);
    }

private:
    void perfSerial(TreeNode* node, string &s) {
        if(node == nullptr) {
            return;
        }
        s += to_string(node->val) + " ";
        perfSerial(node->left, s);
        perfSerial(node->right, s);
    }

    TreeNode* deserial(queue<int>& q, int lo, int hi) {
        if (q.empty()) {
            return NULL;
        }

        int val = q.front();
        if (val < lo || val > hi) {
            return NULL;
        }
        TreeNode* node = new TreeNode(val);
        q.pop();

        node->left = deserial(q, lo, val);
        node->right = deserial(q, val, hi);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
