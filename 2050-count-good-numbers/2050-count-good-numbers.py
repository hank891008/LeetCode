class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = int(1e9 + 7)
        odd = pow(5, (n + 1) // 2, MOD)
        even = pow(4, n // 2, MOD)
        return (odd % MOD * even % MOD) % MOD