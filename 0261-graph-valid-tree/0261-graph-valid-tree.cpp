// Time complexity: O(V + E) for DFS, Space complexity: O(V + E) for creating the graph
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int numEdges = edges.size();

        if (numEdges != n - 1) {
            return false;
        }

    //For a graph to be a tree, it shouldn't have any cycles and all the nodes must be connected.
        vector<vector<int>> graph = buildGraph(n, edges);

        unordered_set<int> visited;

        if (isCyclic(graph, 0, -1, visited)) {
            return false;
        }

        if (visited.size() != n) {
            return false;
        }

        return true;

    }
private:
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    bool isCyclic(vector<vector<int>>& graph, int node, int par, unordered_set<int>& visited) {
        if (visited.count(node)) {
            return true;
        }
        visited.insert(node);

        for (auto &neigh : graph[node]) {
            if (neigh != par && isCyclic(graph, neigh, node, visited)) {
                return true;
            }
        }
        
        return false;

    }

};