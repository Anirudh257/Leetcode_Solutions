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
        if (!root) {
            return "";
        }
        string serl;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            if (!curNode) {
                serl += "#,";
            }
            else {
                serl += to_string(curNode->val) + ",";
            }
            if (curNode) {
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        cout << serl << endl;

        return serl;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) {
            return nullptr;
        }
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        
        TreeNode* node = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(node);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(ss, str, ',');
            
            if (str == "#") {
                node->left = NULL;
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(ss, str, ',');

            if (str == "#") {
                node->right = NULL;
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
