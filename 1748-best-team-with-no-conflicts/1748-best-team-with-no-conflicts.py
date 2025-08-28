class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        n = len(scores)
        p = sorted(zip(scores, ages), key=lambda x: (x[1], x[0]))
        dp = [0] * n
        
        for i in range(n):
            dp[i] = p[i][0]
            for j in range(i):
                if p[i][0] >= p[j][0]:
                    dp[i] = max(dp[i], dp[j] + p[i][0])
        return max(dp)



