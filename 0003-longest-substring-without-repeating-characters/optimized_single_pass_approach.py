# Time complexity: O(N), Space complexity: O(128)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chMap = [None]*128

        left = right = 0

        res = 0

        while right < len(s):
            r = s[right]

            ind = chMap[ord(r)] # ord(ch) -> returns the unicode corresponding to character r

            if ind is not None and left <= ind < right:
                left = ind + 1

            res = max(res, right - left + 1)

            chMap[ord(r)] = right
            right += 1
        
        return res