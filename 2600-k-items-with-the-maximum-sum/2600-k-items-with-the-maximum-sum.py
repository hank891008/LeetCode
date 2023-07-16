class Solution:
    def kItemsWithMaximumSum(self, numOnes: int, numZeros: int, numNegOnes: int, k: int) -> int:
        tot = 0
        if numOnes <= k:
            tot = numOnes
            k -= numOnes
        else:
            return k
        if numZeros <= k:
            k -= numZeros
        else:
            return tot
        return tot - k
            