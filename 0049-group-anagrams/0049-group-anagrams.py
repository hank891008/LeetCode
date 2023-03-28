class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = dict()
        for st in strs:
            sorted_st = ''.join(sorted(st))
            dic.setdefault(sorted_st, []).append(st)
        ret = []
        for values in dic.values():
            ret.append(values)
        return ret