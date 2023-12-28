# Time complexity: O(N), Space complexity: O(N)
class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        max_len = i = 0
        freq = Counter()
        size = len(nums)

        for j in range(size):
            freq[nums[j]] += 1
            while freq[nums[j]] > k:
                freq[nums[i]] -= 1
                i += 1
            max_len = max(max_len, j - i + 1)

        return max_len