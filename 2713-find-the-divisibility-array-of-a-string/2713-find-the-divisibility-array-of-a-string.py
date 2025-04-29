class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        ans = []
        now = 0
        for num in list(word):
            now = (now * 10 + int(num)) % m
            ans.append(int(now == 0))
        return ans