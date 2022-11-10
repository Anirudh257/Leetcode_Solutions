class Solution {
public:
    // Time complexity: O(N), Space complexity: O(N)
    struct Node {
        int st;
        int end;
        int maxElem;
        Node* left;
        Node* right;

        Node() {
            st = 0;
            end = 0;
            maxElem = 0;
            left = NULL;
            right = NULL;
        }

        Node(const vector<int>& itv) {
            st = itv[0];
            end = itv[1];
            maxElem = end;
            left = NULL;
            right = NULL;
        }
    };
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // Interval Tree based approach useful for follow-ups and streaming applications.
        Node* root = NULL;
        bool canAtt = true;
        
        for (auto &x : intervals) {
            if (!root) {
                root = buildTree(root, x);
            }
            else {
                if (searchNode(root, x)) {
                    canAtt = false;
                    break;
                }
                
                addNode(root, x);
                
            }
        }
        
        deleteTree(root);
        
        return canAtt;
    }
private:
    void deleteTree(Node* node) {
        if (node) {
            if (node->left) {
                deleteTree(node->left);
                node->left = NULL;
            }
            if (node->right) {
                deleteTree(node->right);
                node->right = NULL;
            }
        }
        delete node;
    }
    
    Node* buildTree(Node* node, vector<int>& itv) {
        Node* root = new Node(itv);
        return root;
    }
    
    void addNode(Node* node, vector<int>& itv) {
        if (node->left && itv[0] < node->st) {
            addNode(node->left, itv);
            
            if (node->left->maxElem > node->maxElem) {
                node->maxElem = node->left->maxElem;
            }
        }
        else if (node->right && itv[0] >= node->st) {
            addNode(node->right, itv);
                
            if (node->right->maxElem > node->maxElem) {
                node->maxElem = node->right->maxElem;
            }
        }
        else {
            Node* newNode = new Node(itv);
            
            if (itv[0] < node->st) {
                node->left = newNode;
            }
            else {
                node->right = newNode;
            }
            if (node->maxElem < newNode->maxElem) {
                node->maxElem = newNode->maxElem;
            }
        }
        
    }
    
    bool searchNode(Node* node, vector<int>& itv) {
        while (node && !overlap(node, itv)) {
            if (node->left && node->left->maxElem > itv[0]) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        
        if (node) {
            return true;    
        }
        else {
            return false;
        }
    }
    
    bool overlap(Node* node, vector<int>& itv) {
        if (node->st < itv[1] && itv[0] < node->end) {
            return true;
        }
        return false;
    }
    
};
