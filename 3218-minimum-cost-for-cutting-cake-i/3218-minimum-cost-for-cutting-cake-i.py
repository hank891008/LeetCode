class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort(reverse = True)
        verticalCut.sort(reverse = True)
        @cache
        def dp(i, j):
            if i == m - 1 and j == n - 1:
                return 0
            elif i == m - 1:
                return dp(i, j + 1) + (i + 1) * verticalCut[j]
            elif j == n - 1:
                return dp(i + 1, j) + (j + 1) * horizontalCut[i]
            else:
                return min(dp(i, j + 1) + verticalCut[j] * (i + 1), dp(i+ 1, j) + horizontalCut[i] * (j + 1))
        
        return dp(0, 0)