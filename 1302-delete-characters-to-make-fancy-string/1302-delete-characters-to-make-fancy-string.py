class Solution:
    def makeFancyString(self, s: str) -> str:
        ans = s[0]
        cnt = 1
        for i, c in enumerate(s[1:]):
            if c == ans[-1]:
                cnt += 1
                if cnt > 2:
                    continue
                else:
                    ans += c
            else:
                ans += c
                cnt = 1
        return ans