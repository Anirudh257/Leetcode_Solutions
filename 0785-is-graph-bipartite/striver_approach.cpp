// Time complexity: O(N + E), N = number of nodes, E = number of edges
// Space complexity: O(N) for queue + O(N) for color graph + O(N) Auxiliary space 
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Use BFS logic using queues to color the nodes and keep inserting into queue
        // after color has been done. Adjacent nodes should have 2 different colors.
        // If no odd-length cycle detected, graph is bipartite
        int n = graph.size();
        return checkBipar(graph, n);
    }
private:
    bool bfsCheck(int node, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = 0;
        queue<int> q;
        q.push(node);

        while(!q.empty()) {
            int top = q.front();
            q.pop();
            int currCol = color[top];

            for (int neigh : graph[top]) {
                if (color[neigh] == -1) {
                    color[neigh] = abs(1 - currCol);
                    q.push(neigh);
                }
                else {
                    if (color[neigh] == currCol) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool checkBipar(vector<vector<int>>& graph, int n) {
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfsCheck(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};
