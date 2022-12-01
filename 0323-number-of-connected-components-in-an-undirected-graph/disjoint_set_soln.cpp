class Solution {
public:
    // Disjoint set union approach
    // Time complexity: O(E.alpha(n)) for iteration over E edges and O(alpha(n)) for Inverse Ackermann function.
    // Space complexity: O(V) for parent array 
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        int numComps = n;
        
        for (auto e : edges) {
            numComps -= addEdge(e[0], e[1], parent, rank);
        }
        return numComps;
    }
private:
    int findPar(int x, vector<int>& parent) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findPar(parent[x], parent);
    }
    
    int addEdge(int x, int y, vector<int>& parent, vector<int>& rank) {
        x = findPar(x, parent);
        y = findPar(y, parent);
        
        if (x == y) {
            return 0;
        }
        else {
            if (rank[x] > rank[y]) {
                parent[y] = x;
                rank[x] += rank[y];
            }
            else {
                parent[x] = y;
                rank[y] += rank[x];
            }
            return 1;
        }
        
    }
};
