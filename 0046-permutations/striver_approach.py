# TC: O(n!*n), SC: O(n) for storing visit + O(n) for storing perm.
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        all_perms = []
        size = len(nums)
        perm = []
        visit = [False]*size

        self.create_perm(perm, all_perms, nums, visit, size)
        return all_perms

    def create_perm(self, perm, all_perms, nums, visit, size):
        if len(perm) == size:
            perm_cp = copy.copy(perm)
            all_perms.append(perm_cp)
            return 
        else:
            for i in range(0, size):
                if visit[i] == False:
                    perm.append(nums[i])
                    visit[i] = True
                    
                    self.create_perm(
                        perm = perm, 
                        all_perms = all_perms, 
                        nums = nums, 
                        visit = visit, 
                        size = size,
                    )
                    del perm[-1]
                    visit[i] = False
