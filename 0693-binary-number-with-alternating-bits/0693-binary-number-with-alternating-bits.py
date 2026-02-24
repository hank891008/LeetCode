class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        tmp = n ^ (n >> 1)
        return tmp & (tmp + 1) == 0