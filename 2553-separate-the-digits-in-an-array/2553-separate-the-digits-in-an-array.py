class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = ''
        for i in nums:
            ans += str(i)
        ans = map(int, list(ans))
        return ans