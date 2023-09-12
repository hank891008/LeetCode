class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        from itertools import combinations
        comb = combinations([i for i in range(1, 10)], k)
        ans = []
        for i in list(comb):
            if sum(i) == n:
                ans.append(i)
        return ans