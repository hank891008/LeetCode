class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        @cache
        def solve(x):
            if x == 1:
                return 0
            elif x % 2 == 0:
                return 1 + solve(x // 2)
            else:
                return 1 + solve(3 * x + 1)
        arr = []
        for i in range(lo, hi + 1):
            arr.append([i, solve(i)])
        arr.sort(key=lambda x: x[1])
        return arr[k - 1][0]