// Time complexity: O(V + E), Space complexity: O(V + E)
vector<int> compDFS(int node, vector<bool>& visited, vector<int> graph[], vector<int>& trav) {
    visited[node] = true;
    trav.push_back(node);

    for (int neigh : graph[node]) {
        if (!visited[neigh]) {
            trav = compDFS(neigh, visited, graph, trav);
        }
    }

    return trav;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> dfsTrav;
    vector<bool> visited(V);
    vector<int> graph[V];

    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> trav;
            trav = compDFS(i, visited, graph, trav);
            dfsTrav.push_back(trav);
        }
    }


    return dfsTrav;
}