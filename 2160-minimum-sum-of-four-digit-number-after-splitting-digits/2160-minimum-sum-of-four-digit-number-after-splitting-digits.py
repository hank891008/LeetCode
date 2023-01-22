class Solution:
    def minimumSum(self, num: int) -> int:
        num = sorted(list(map(int, list(str(num)))))
        return (num[0] + num[1] + (num[2] + num[3]) // 10) * 10 + (num[2] + num[3]) % 10