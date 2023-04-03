// Time complexity: O(N^2), Space complexity: O(N)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size(), maxLen = 0;
        // vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        vector<int> curr(len2 + 1, 0), prev(len2 + 1, 0);

        for (int ind1 = 1; ind1 <= len1; ind1++) {
            for (int ind2 = 1; ind2 <= len2; ind2++) {
                int take = 0;
                if (nums1[ind1 - 1] == nums2[ind2 - 1]) {
                    take = 1 + prev[ind2 - 1];
                }
                else {
                    take = 0;
                }
                curr[ind2] = take;
                maxLen = max(maxLen, curr[ind2]);
            }
            prev = curr;
        }

        return maxLen;
    }
};