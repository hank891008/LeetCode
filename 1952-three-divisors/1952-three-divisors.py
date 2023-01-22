class Solution:
    def isThree(self, n: int) -> bool:
        if n == 1:
            return False
        if int(sqrt(n)) ** 2 == n:
            n /= sqrt(n)
            for i in range(2, int(sqrt(n)) + 1):
                if n % i == 0:
                    return False
            return True
        return False