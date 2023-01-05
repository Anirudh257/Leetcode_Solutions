// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int numWater = 0, left = 0, right = size - 1, leftMax = 0, rightMax = 0;

        while(left <= right) {
            if (height[left] <= height[right]) {
                if (leftMax < height[left]) {
                    leftMax = height[left];
                }
                else {
                    numWater += leftMax - height[left];
                }
                left++;
            }
            else {
                if (rightMax < height[right]) {
                    rightMax = height[right];
                }
                else {
                    numWater += rightMax - height[right];
                }
                right--;
            }
        }

        return numWater;
    }
};
