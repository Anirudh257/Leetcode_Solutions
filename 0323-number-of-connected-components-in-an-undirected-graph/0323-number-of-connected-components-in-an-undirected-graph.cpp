// Time complexity: O(V + E), Space complexity: O(V + E): O(E) to build graph + 
// O(V) for visited graph + Auxiliary space of O(V)
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int numComps = 0;
        vector<int> adjList[n];
        vector<bool> visited(n, false);
        
        // Build the graph
        for (auto edge: edges) {
            int src = edge[0], dest = edge[1];
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                numComps++;
                dfs(i, adjList, visited, n);
            }
        }


        return numComps;    
    }
private:
    void dfs(int node, vector<int> adjList[], vector<bool>& visited, int n) {
        visited[node] = true;
        for (auto neigh : adjList[node]) {
            if (!visited[neigh]) {
                dfs(neigh, adjList, visited, n);
            }
        }
    }
};