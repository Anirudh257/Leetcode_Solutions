// Time complexity: O(1), Space complexity: O(1)
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // Mathematical approach: 3 points having an area of triangle = 0
        // means that the lines are collinear 
        double trArea = points[0][0]*(points[1][1] - points[2][1]) + points[1][0]*(points[2][1] - points[0][1]) + points[2][0]*(points[0][1] - points[1][1]);

        return trArea != 0;
    }
};