// Time complexity: O(1), Space complexity: O(1)
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        
        if (isPointSame(points[0], points[1]) || isPointSame(points[1], points[2]) || isPointSame(points[0], points[2])) {
            return false;
        }
                
        double slope_1_0 = 0.0, slope_1_2= 0;
        if (points[1][0] != points[0][0]) {
            slope_1_0 =  ((double)(points[1][1] - points[0][1])/((points[1][0] - points[0][0])));   
        }
        else {
            slope_1_0 = 1e9;
        }
        if (points[1][0] != points[2][0]) {
            slope_1_2 = ((double)(points[1][1] - points[2][1])/((points[1][0] - points[2][0])));           
        }
        else {
            slope_1_2 = 1e9;
        }
                
        return slope_1_0 != slope_1_2;
    }
private:
    bool isPointSame(vector<int>& point1, vector<int>& point2) {
        return point1[0] == point2[0] && point1[1] == point2[1];
    }
};