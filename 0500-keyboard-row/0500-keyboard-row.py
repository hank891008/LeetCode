class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        ret = []
        f = set("qwertyuiop")
        s = set("asdfghjkl")
        t = set("zxcvbnm")
        for word in words:
            w = set(word.lower())
            if w.issubset(f) or w.issubset(s) or w.issubset(t):
                ret.append(word)
        return ret