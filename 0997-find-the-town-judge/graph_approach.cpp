// Time complexity: O(V + E), Space complexity: O(V + E)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph = buildGraph(trust, n);
        vector<int> inDeg = compInDegree(graph);
        int judge = -1;

        for (int i = 1; i <= n; i++) {
            if (inDeg[i] == n - 1 && graph[i].size() == 0) {
                judge = i;
            }
        }

        return judge;
    }
private:
    vector<int> compInDegree(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDeg(n, 0);

        for (int i = 0; i < graph.size(); i++) {
            for (auto &x : graph[i]) {
                inDeg[x]++;
            }
        }

        return inDeg;
    }

    vector<vector<int>> buildGraph(vector<vector<int>>& trust, int n) {
        vector<vector<int>> graph(n + 1);
        for (auto &x : trust) {
            graph[x[0]].push_back(x[1]);
        }

        // printGraph(graph);

        return graph;
    }
    void printGraph(vector<vector<int>>& graph) {
        for (int i = 0; i < graph.size(); i++) {
            cout << i << " -> ";
            for (auto &x : graph[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};
