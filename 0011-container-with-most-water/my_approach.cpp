// Time complexity: O(n), Space complexity: O(1)
// The objective is to maximize area and hence maximize height and maximize width
// Starting at the maximum width, l = 0, r = size - 1, we move towards maximum height, as it is
// bound by min(a[l], a[r]). Keep moving pointer pointing to lower height.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int l = 0, r = size - 1, h, w, currArea = -1;
        int maxArea = -1;

        while(l < r && r >= 0) {
            h = min(height[l], height[r]);
            w = r - l;
            currArea = h*w;
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};