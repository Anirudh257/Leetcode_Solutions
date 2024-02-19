# Time complexity: O(N), Space complexity: O(N)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chMap = {}
        size = len(s)
        l = r = 0
        max_len = -1e9

        while r < size:
            ch = s[r]
            if ch in chMap:
                l = max(l, chMap[ch] + 1)
            chMap[ch] = r

            max_len = max(max_len, r - l + 1)
            r+= 1
        
        if max_len == -1e9:
            return size

        return max_len