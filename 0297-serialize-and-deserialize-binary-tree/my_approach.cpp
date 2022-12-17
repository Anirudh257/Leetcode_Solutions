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
        string serl;

        perfSerial(root, serl);

        // cout << serl << endl;
        return serl;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        istringstream iss(data);
        string s;
        queue<string> q;

        while(iss >> s) {
            q.push(s);
        }

        return deser(q);
    }
private:
    TreeNode* deser(queue<string>& q) {
        if (q.empty()) {
            return nullptr;
        }
        int val = stoi(q.front());
        
        if (val == 1001) {
            q.pop();
            return nullptr;
        }

        q.pop();
        TreeNode* node = new TreeNode(val);

        node->left = deser(q);
        node->right = deser(q);

        return node;
    }

    void perfSerial(TreeNode* node, string& serl) {
        if(!node) {
            serl += "1001 ";
            return;
        }
        serl += to_string(node->val) + " ";

        perfSerial(node->left, serl);
        perfSerial(node->right, serl);
    }

    void printQ(queue<string> q) {
        while(!q.empty()) {
            cout << q.front() << endl;
            q.pop();
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
