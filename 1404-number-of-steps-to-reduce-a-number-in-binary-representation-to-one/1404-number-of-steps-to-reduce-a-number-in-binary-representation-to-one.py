class Solution:
    def numSteps(self, s: str) -> int:
        num = 0
        for bit in s:
            num = (num << 1) + int(bit)
        cnt = 0
        while num != 1:
            if num & 1:
                num += 1
            else:
                num >>= 1
            cnt += 1
        return cnt