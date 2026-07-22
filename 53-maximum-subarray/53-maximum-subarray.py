class Solution:
    # Time complexity: O(N), Space Complexity: O(1)
    def maxSubArray(self, nums: List[int]) -> int:

        if not nums:
            raise ValueError("nums must not be a non-empty list")

        max_sum = curr_sum = nums[0]

        for x in nums:
            # At each step, we can start a new sub-array from the current element [x]
            # Or we can add the current element to the existing sub-array [curr_sum + x]
            curr_sum = max(x, curr_sum + x)
            max_sum = max(max_sum, curr_sum)
        return max_sum