class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        b = ''.join(str(i) for i in b)
        return pow(a, int(b), 1337)