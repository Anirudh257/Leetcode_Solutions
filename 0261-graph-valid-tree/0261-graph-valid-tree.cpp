class Solution {
public:
    // Time comlexity: O(V + E), Space complexity: O(V + E)
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }   
        vector<bool> visited(n, false);
        
        vector<vector<int>> g = buildGraph(edges, n);
        
        if (isCyclic(g, 0, -1, visited)) {
            return false;
        }
        
        for (auto x : visited) {
            if (!x) {
                return false;
            }
        }
        
        return true;
    }
private:
    vector<vector<int>> buildGraph(vector<vector<int>>& edges, int n) {
        vector<vector<int>> g(n);
        
        for (auto &x : edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
            
        }
        return g;
    }
    
    bool isCyclic(vector<vector<int>>& g, int node, int par, vector<bool>& visited) {
        if (visited[node]) {
            return true;
        }
        visited[node] = true;
        
        for (auto neigh : g[node]) {
            if (neigh != par && isCyclic(g, neigh, node, visited)) {
                return true;
            }
        }
        return false;
    }
};