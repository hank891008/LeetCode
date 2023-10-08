class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        return sum(map(lambda x: x[0] <= queryTime <= x[1], list(zip(startTime, endTime))))