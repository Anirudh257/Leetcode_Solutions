// Time complexity: O(N), Space complexity: O(2N)
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int numWater = 0;
        vector<int> left(size, 0), right(size, 0);
        left[0] = height[0], right[size - 1] = height[size - 1];

        for (int i = 1; i < size; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        // for (auto &x : left) {
        //     cout << x << endl;
        // }

        for (int i = size - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        for (int i = 1; i < size - 1; i++) {
            int h = min(left[i], right[i]);
            numWater += (h - height[i]);
        }

        return numWater;

    }
};
