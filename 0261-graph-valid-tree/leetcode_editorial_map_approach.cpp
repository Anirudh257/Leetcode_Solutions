// Time complexity: O(V + E), Space complexity: O(V + E) + O(V)
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int numEdges = edges.size();
        
        // Rudimentary check of cycle in graph.
        if (numEdges != n - 1) {
            return false;
        }

        unordered_map<int, int> par;
        par[0] = -1;
        stack<int> st;
        st.push(0);


        vector<vector<int>> g = buildGraph(n, edges);

        while(!st.empty()) {
            int top = st.top();
            st.pop();
            for (int neigh : g[top]) {
                if (par[top] == neigh) {
                    continue;
                }
                if (par.find(neigh) != par.end()) {
                    return false;
                }
                st.push(neigh);
                par[neigh] = top;
            }
        }

        return par.size() == n;

        // unordered_set<int> visited;

        // // No cycle in graph
        // if (isCycle(g, 0, -1, visited)){
        //     return false;
        // }

        // // from 0, if all nodes are not visited, graph is disjoint.
        // if (visited.size() != n) {
        //     return false;
        // }


        // return true;
    }
private:
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto &x : edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }        

        return graph;
    }

    bool isCycle(vector<vector<int>>& g, int node, int prev, unordered_set<int>& visited) {
        if (visited.count(node)) {
            return true;
        }
        visited.insert(node);

        for (int neigh : g[node]) {
            if (neigh != prev && isCycle(g, neigh, node, visited)) {
                return true;
            }
        }
        return false;

    }
};