// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return max(slideWin(nums1, nums2), slideWin(nums2, nums1));
    }
private:
    int slideWin(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size(), maxLen = 0, currLen = 0;

        for (int st = 0; st < len2; st++) {
            currLen = 0;
            for (int i = 0; i < len1 && st + i < len2; i++) {
                if (nums1[i] == nums2[st + i]) {
                    currLen++;
                }
                else {
                    currLen = 0;
                }
                maxLen = max(maxLen, currLen);
            }

        }

        return maxLen;
    }
};