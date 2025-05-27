class Solution:
    def numWays(self, s: str) -> int:
        MOD = int(1e9 + 7)
        mp = {}
        cnt = 0
        for i, ch in enumerate(s):
            if ch == '1':
                cnt += 1
                mp[cnt] = i
        if cnt % 3 != 0:
            return 0
        elif cnt == 0:
            return math.comb(len(s) - 1, 2) % MOD
        print(cnt, cnt // 3)
        first = mp[cnt // 3 + 1] - mp[cnt // 3]
        second = mp[2 * cnt // 3 + 1] - mp[2 * cnt // 3]
        return first * second % MOD
            
