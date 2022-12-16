// Time complexity: O(N), Space complexity: O(N)
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
        inorderDFS(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserial(data, pos, INT_MIN, INT_MAX);
    }
private:
    void inorderDFS(TreeNode* root, string& s) {
        if (!root) {
            return;
        }
        
        // Storing in char to save memory
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int));
        
        for (int i = 0; i < 4; i++) {
            s.push_back(buf[i]);
        }

        inorderDFS(root->left, s);
        inorderDFS(root->right, s);
    }

    TreeNode* deserial(string& buff, int& pos, int lo, int hi) {
        if (pos >= buff.size()) {
            return NULL;
        }

        int val;
        memcpy(&val, &buff[pos], sizeof(int));

        if (val < lo || val > hi) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(val);

        pos += sizeof(int);
        node->left = deserial(buff, pos, lo, val);
        node->right = deserial(buff, pos, val, hi);

        return node;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
