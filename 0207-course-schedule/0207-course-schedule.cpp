class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        
        vector<int> indeg = calcIndegrees(g);
        
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!indeg[j]) {
                    break;
                }
            }
            
            // No node with indegree = 0 remains, presence of a cycle.
            if (j == numCourses) {
                return false;
            }
            indeg[j]--;
            for (int adj : g[j]) {
                indeg[adj]--;
            }
            
        }
        
        
        
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);
        
        for (auto &p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        return g;
        
    }
    
    vector<int> calcIndegrees(graph &g) {
        vector<int> indeg(g.size(), 0);
        
        for (auto &x : g) {
            for (auto &adj : x) {
                indeg[adj]++;
            }
        }
        return indeg;
        
    }
};