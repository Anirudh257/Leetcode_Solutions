// Time complexity: O(V + E), Space complexity: O(V + E) to create the graph
// O(V) for queue and visited boolean vector.
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> bfsOut;
    vector<int> graph[n];

    for (int i = 0; i < n; i++) {
        for (auto e : adj[i]) {
            if (e != 0) {
                graph[i].push_back(e);
            }
        }
    }
    vector<bool> visited(n);
    
    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int top = q.front();
        q.pop();

        if (!visited[top]) {
            bfsOut.push_back(top);
            visited[top] = true;
        }
        for (auto neigh : graph[top]) {
            if (!visited[neigh]) {
                q.push(neigh);
            }
        }
    }

    return bfsOut;
}