class Solution {
public:
    // Time complexity: O(V + E) to travverse the DFS + O(E) to build adjacency list
    // Space complexity: O(V + E) to build DFS + O(E) to build visited list
    
    int countComponents(int n, vector<vector<int>>& edges) {
        // DFS approach
        vector<bool> visited(n, false);
        vector<int> adjList[n];
        int numComps = 0;
        
        for (auto e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                numComps++;
                dfs(i, n, adjList, visited);
            }
        }
        
        return numComps;
    }
private:
    void dfs(int node, int n, vector<int> adjList[], vector<bool>& visited) {
        visited[node] = true;
        
        for (auto neigh : adjList[node]) {
            if (!visited[neigh]) {
                dfs(neigh, n, adjList, visited);
            }
        }
        
    }
};