class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        ret = 0
        for p in patterns:
            if word.find(p) != -1:
                ret += 1
        print(ret)
        return ret