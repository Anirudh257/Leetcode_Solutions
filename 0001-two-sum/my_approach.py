# Time complexity: O(N), Space complexity: O(N)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        umap = {}
        size = len(nums)

        for i in range(size):
            num = nums[i]
            complement = target - num
            if complement in umap:
                return [umap[complement], i]
            umap[num] = i
        
        return []