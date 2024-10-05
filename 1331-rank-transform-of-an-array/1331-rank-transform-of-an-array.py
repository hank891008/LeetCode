class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        s = sorted(list(set(arr)))
        d = {}
        for i in range(len(s)):
            d[s[i]] = i + 1
        return list(map(lambda x: d[x], arr))