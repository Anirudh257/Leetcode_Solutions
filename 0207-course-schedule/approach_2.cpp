class Solution {
public:
    // Time complexity: O(N + E), Space complexity: O(N), N = number of nodes, E = number of edges
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, i, todo, done)) {
                return false;
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
    
    bool acyclic(graph& g, int node, vector<bool>& todo, vector<bool>& done) {
        // Cycle detected.
        if (todo[node]) {
            return false;
        }
        
        
        if (done[node]) {
            return true;
        }
        
        // todo -> nodes to be visited, done -> nodes visited
        
        
        todo[node] = done[node] = true;
        
        for (int neigh : g[node]) {
            if (!acyclic(g, neigh, todo, done)) {
                return false;
            }
        }
        
        todo[node] = false;
        return true;
        
    }
    
};
