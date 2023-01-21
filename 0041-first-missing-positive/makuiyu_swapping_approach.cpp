// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Swap till all numbers in the correct position
        vector<int> cp = nums;
        int size = cp.size();

        // Keep swapping till 5 not at A[4].
        for (int i = 0; i < size; i++) {
            while(cp[i] > 0 && cp[i] <= size && cp[cp[i] - 1] != cp[i]) {
                swap(cp[i], cp[cp[i] - 1]);
            }
        }

        for (int i = 0; i < size; i++) {
            if (cp[i] != i + 1) {
                return i + 1;
            }
        }


        return size + 1;
    }
};
