class Solution:
    def countSeniors(self, details: List[str]) -> int:
        details = list(map(lambda x: int(x[11:-2]) > 60, details))
        return sum(details)