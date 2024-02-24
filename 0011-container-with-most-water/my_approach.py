# Time complexity: O(n), Space complexity: O(1)
class Solution:
    def maxArea(self, height: List[int]) -> int:
        size = len(height)
        max_area = curr_area = -1
        l, r = 0, size - 1

        while l < r:
            h = min(height[l], height[r])
            w = r - l
            curr_area = h*w
            max_area = max(max_area, curr_area)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        
        return max_area

            