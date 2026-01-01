# Time complexity: O(2*n), Space complexity: O(n)
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        contains = s.__contains__
        best = 0

        # Avoid re-iterating through same element
        for n in s:
            if not contains(n - 1):
                x = n
                while contains(x):
                    x += 1
                best = max(best, x - n)
        return best