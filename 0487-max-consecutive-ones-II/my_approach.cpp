// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size(), maxOnes = 0, currOnes = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                maxOnes = max(maxOnes, currOnes);
                currOnes = 0;
            }
            else {
                currOnes++;
            }
        }

        maxOnes = max(maxOnes, currOnes);


        vector<int> left(size, 0), right(size, 0);

        for (int i = 1; i < size; i++) {
            if (nums[i - 1] == 1) {
                left[i] = 1 + left[i - 1];
            }
        }

        for (int i = size - 2; i >= 0; i--) {
            if (nums[i + 1] == 1) {
                right[i] = 1 + right[i + 1];
            }
        }

        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                int curOnes = 1 + left[i] + right[i];
                maxOnes = max(maxOnes, curOnes);
            }
        }

        return maxOnes;
    }
};
