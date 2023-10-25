# Time complexity: O(N), Space complexity: O(1)
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        fin_prod = [1]*len(nums)
        prefix = 1

        for i in range(len(nums)):
            fin_prod[i] = prefix
            prefix *= nums[i]

        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            fin_prod[i] *= postfix
            postfix *= nums[i]

        return fin_prod