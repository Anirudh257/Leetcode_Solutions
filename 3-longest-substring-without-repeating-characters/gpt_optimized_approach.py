# Time complexity: O(N), Space complexity: O(N)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last = {}
        left = 0 # Start of the current window
        best = 0

        for right, ch in enumerate(s):
            
            if ch in last and last[ch] >= left:
                left = last[ch] + 1

            last[ch] = right

            best = max(best, right - left + 1)

        return best