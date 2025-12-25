class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness = sorted(happiness, reverse=True)
        ans = 0
        for i in range(k):
            ans += max(happiness[i] - i, 0)
        return ans