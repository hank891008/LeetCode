class Solution:
    def alternateDigitSum(self, n: int) -> int:
        ret = 0
        n = str(n)
        for i in range(len(n)):
            ret += int(n[i]) if i % 2 == 0 else -int(n[i])
        return ret