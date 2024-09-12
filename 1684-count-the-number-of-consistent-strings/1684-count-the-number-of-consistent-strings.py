class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        return sum([len(set(word) - set(allowed)) == 0 for word in words])