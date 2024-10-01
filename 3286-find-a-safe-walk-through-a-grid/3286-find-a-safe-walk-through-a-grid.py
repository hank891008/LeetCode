class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        n = len(grid)
        m = len(grid[0])
        used = [[0 for i in range(m)] for i in range(n)]
        
        @cache
        def dfs(x, y, tot):
            if x < 0 or x >= n or y >= m or y < 0 or used[x][y] or tot >= health:
                return float('inf')
            if x == n - 1 and y == m - 1:
                return tot + grid[n - 1][m - 1]
            
            minn = float('inf')
            used[x][y] = 1
            for (i, j) in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                minn = min(minn, dfs(x + i, y + j, tot + grid[x][y]))
            used[x][y] = 0
            
            return minn
        
        return dfs(0, 0, 0) < health