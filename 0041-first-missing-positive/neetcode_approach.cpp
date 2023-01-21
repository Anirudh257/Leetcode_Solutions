// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int small = 1, size = nums.size();

        vector<int> cp = nums;

        // small can only be in the range [1, size + 1]
        // Using this fact, we can use the elements of array as indices of the array
        // and mark the numbers as negative meaning that the element has been visited.
        // If the number is already negative, it is better to make it 0 first and then 
        // mark it as -1*(size(nums) + 1)

        // Mark negative numbers as 0 as they don't contribute to solution. 
        // Marking 0 is better than marking as 1 as 1 is a possible smallest missing
        // number.
        for (int i = 0; i < size; i++) {
            if (cp[i] < 0) {
                cp[i] = 0;
            }
        }

        for (int i = 0; i < size; i++) {
            
            // Using the numbers itself as index and marking the corresponding 
            // number at that index as negative. Also, check if that index doesn't
            // overshoot the array bounds.
            int ind = abs(cp[i]);

            if (ind >= 1 && ind <= size) {
                if (cp[ind - 1] > 0) {
                    cp[ind - 1] *= -1;
                }
                else if (cp[ind - 1] == 0) {
                    cp[ind - 1] = -1*(size + 1);
                }
            }
        }

        // If the number at the possible index is not negative, this means 
        // that it has been unvisited and index should be the smallest possible 
        // positive number
        for (int i = 1; i <= size; i++) {
            if (cp[i - 1] >= 0) {
                return i;
            }
        }
        

        return size + 1;

    }
};
