class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        @cache
        def dfs(i, j, s):
            maxx = 0
            if j - i + 1 >= 2:
                if nums[i] + nums[i + 1] == s:
                    maxx = max(maxx, 1 + dfs(i + 2, j, s))
                if nums[i] + nums[j] == s:
                    maxx = max(maxx, 1 + dfs(i + 1, j - 1, s))
                if nums[j] + nums[j - 1] == s:
                    maxx = max(maxx, 1 + dfs(i, j - 2, s))
            return maxx
                
        
        return max(
            dfs(0, len(nums) - 3, nums[-1] + nums[-2]),
            dfs(1, len(nums) - 2, nums[0] + nums[-1]),
            dfs(2, len(nums) - 1, nums[1] + nums[0]),
        ) + 1