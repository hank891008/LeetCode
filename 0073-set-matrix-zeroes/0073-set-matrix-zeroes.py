class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        r = []
        c = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    r.append(i)
                    c.append(j)
        r = set(r)
        c = set(c)
        print(r)
        print(c)
        for i in r:
            for j in range(len(matrix[0])):
                matrix[i][j] = 0
        for j in c:
            for i in range(len(matrix)):
                matrix[i][j] = 0