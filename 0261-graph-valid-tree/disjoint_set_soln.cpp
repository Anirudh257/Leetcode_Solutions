class Solution {
public:
    // Time complexity:O(V + E), Space complexity: O(1)
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n -1) {
            return false;
        }
        vector<int> nodes(n, 0);
        
        for (int i = 0; i < n; i++) {
            nodes[i] = i;
        }
        
        for (auto &x : edges) {
            int f = x[0];
            int s = x[1];
            while(nodes[f] != f) {
                f = nodes[f];
            }
            while(nodes[s] != s) {
                s = nodes[s];
            }
            // belong to the same disjoint set
            if (s == f) {
                return false;
            }
            
            nodes[s] = f;
            
        }
        
        return true;
    }
};
