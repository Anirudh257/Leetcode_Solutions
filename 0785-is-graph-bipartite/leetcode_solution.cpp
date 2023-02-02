// Time complexity: O(N + E) N = number of nodes, E = number of edges to explore the graph
// Space complexity: O[N] [color] + O[N] for stack
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                stack<int> st;
                st.push(i);
                color[i] = 0;

                while(!st.empty()) {
                    int top = st.top();
                    int col = color[top];
                    st.pop();

                    for (int neigh : graph[top]) {
                        if (color[neigh] == -1) {
                            st.push(neigh);
                            color[neigh] = abs(1 - col);
                        }
                        else if (color[neigh] == col) {
                            return false;
                        }
                    }

                }

            }
        }

        return true;
    }
};
