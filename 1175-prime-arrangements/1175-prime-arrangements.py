class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
        MOD = 1000000007
        @cache
        def factorial(x):
            return 1 if x <= 1  else ((x % MOD) * (factorial(x - 1) % MOD)) % MOD
        
        num_of_p = sum(list(map(lambda x: x in prime, range(2, n + 1))))
        
        return ((factorial(num_of_p) % MOD) * (factorial(n - num_of_p) % MOD)) % MOD