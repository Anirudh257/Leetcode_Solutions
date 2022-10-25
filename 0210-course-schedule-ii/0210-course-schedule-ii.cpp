class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ordering;
        graph g = buildGraph(prerequisites, numCourses);
        
        vector<int> indeg = compIndeg(g);
        
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (indeg[j] == 0) {
                    break;
                }
            }
            
            if (j == numCourses) {
                return {};
            }
            indeg[j]--;
            
            ordering.push_back(j);
            
            for (int adj : g[j]) {
                indeg[adj]--;
            }
            
        }
        
        return ordering;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(vector<vector<int>>& prerequisites, int numCourses) {
        graph g(numCourses);
        for (auto &x : prerequisites) {
            g[x[1]].push_back(x[0]);
        }
        
        return g;
    }
    
    vector<int> compIndeg(graph& g) {
        vector<int> indegrees(g.size(), 0);
        
        for (auto &x : g) {
            for (auto &adj : x) {
                indegrees[adj]++;
            }
        }
        return indegrees;
        
    }
    
};