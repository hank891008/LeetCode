class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        def myPow(a, b, n = 1337):
            ret = 1
            while b != 0:
                if b & 1:
                    ret = (ret * a) % n
                a = (a * a) % n
                b = b >> 1
            return ret
        return myPow(a, int(''.join(map(str, b))))