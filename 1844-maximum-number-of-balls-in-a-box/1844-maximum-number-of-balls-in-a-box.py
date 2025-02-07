class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        def solve(x):
            sum = 0
            while x != 0:
                sum += x % 10
                x //= 10
            return sum
        boxes = [0 for _ in range(46)]
        for i in range(lowLimit, highLimit + 1):
            boxes[solve(i)] += 1
        return max(boxes)