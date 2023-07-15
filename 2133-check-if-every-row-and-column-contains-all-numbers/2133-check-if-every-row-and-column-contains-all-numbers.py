class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        for i in range(n):
            li1, li2 = [], []
            for j in range(n):
                li1.append(matrix[i][j])
                li2.append(matrix[j][i])
            for j in range(n):
                if li1.count(j + 1) == 0 or li2.count(j + 1) == 0:
                    return False
        return True