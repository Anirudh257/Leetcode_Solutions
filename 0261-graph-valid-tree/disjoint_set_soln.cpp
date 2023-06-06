// Time complexity: O(E.alpha(V)) for Union-finding each edge,
// Space complexity: O(V)
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int numEdges = edges.size();
        if (numEdges != n - 1) {
            return false;
        }

        vector<int> parent(n), rank(n);

        for (int i = 0; i < n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }

        // For the graph to be a tree, all the nodes must be in 1 component(all connected)
        // and no cycle
        for (auto &edge: edges) {
            if (!perfUnion(edge[0], edge[1], parent, rank)) {
                return false;
            }
        }

        return true;
    }
private:
    int findPar(int node, vector<int>& parent) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node], parent);
    }

    bool perfUnion(int x, int y, vector<int>& parent, vector<int>& rank) {
        int parX = findPar(x, parent);
        int parY = findPar(y, parent);

        // Cycle exists as edge between nodes already belonging to the same component.
        if (parX == parY) {
            return false;
        }
        else {
            if (rank[parX] > rank[parY]) {
                parent[parY] = parX;
                rank[parX] += rank[parY];
            } 
            else {
                parent[parX] = parY;
                rank[parY] += rank[parX];
            }
        }
        return true;

    }
};