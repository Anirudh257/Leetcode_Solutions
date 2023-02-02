// Time complexity: O(N + E), Space complexity: O(N + E)
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        set<vector<int>> visited;
        return perfDFS(maze, start, destination, visited);
    }
private:
    bool perfDFS(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, set<vector<int>>& visited) {
        if (start == destination) {
            return true;
        }
        if (visited.find(start) != visited.end()) {
            return false;
        }
        visited.insert(start);

        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < 4; i++) {
            // Keep going through 1 direction till you reach a dead-end/destination
            vector<int> res = go2End(maze, start, dirs[i]);

            if (res == destination || perfDFS(maze, res, destination, visited)) {
                return true;
            }
        }
        return false;
    }

    vector<int> go2End(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir) {
        int x = start[0] + dir[0];
        int y = start[1] + dir[1];
        int m = maze.size(), n = maze[0].size();

        if (x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == 1) {
            return start;
        }
        vector<int> newSt = {x, y};

        return go2End(maze, newSt, dir);

    }

};
