class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxx = max(candies)
        ans = []
        for c in candies:
            if c + extraCandies >= maxx:
                ans.append(True)
            else:
                ans.append(False)
        return ans