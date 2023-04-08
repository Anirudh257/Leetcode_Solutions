# Time complexity: O(N), Space complexity: O(1)
class Solution:
    def firstUniqChar(self, s: str) -> int:

        counts = {}
        for ch in s:
            counts[ch] = 0
        
        for ch in s:
            counts[ch]+= 1

        size = len(s)
        for i in range(size):
            if counts[s[i]] == 1:
                return i

        return -1