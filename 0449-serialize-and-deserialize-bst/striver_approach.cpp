// Time complexity: O(V), Space complexity: O(V)
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
        string ser = "";
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            if (top) {
                ser.append(to_string(top->val) + ",");
                q.push(top->left);
                q.push(top->right);
            }
            else {
                ser.append("#,");
            }
        }

        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data.size() == 0) {
            return NULL;
        }

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") {
                top->left = NULL;
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                top->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');

            if (str == "#") {
                top->right = NULL;
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                top->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;