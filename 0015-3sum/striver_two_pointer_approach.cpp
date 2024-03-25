// Time complexity: O(n^2) + O(nlogn), Space complexity: O(#triplets)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        return comp3Sum(nums, size);
    }

private:
    vector<vector<int>> comp3Sum(vector<int>& nums, int& size) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;

        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = size - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    triplets.push_back(temp);
                    j++, k--;

                    while(j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    
                    while(j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return triplets;
    }

};