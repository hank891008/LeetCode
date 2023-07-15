class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            li = []
            for j in range(9):
                li.append(board[i][j])
            for j in range(1, 10):
                if li.count(str(j)) >= 2:
                    return False
        for i in range(9):        
            li = []
            for j in range(9):
                li.append(board[j][i])
            for j in range(1, 10):
                if li.count(str(j)) >= 2:
                    return False
        for i in range(3):
            for j in range(3):
                li = []
                for k in range(3):
                    for l in range(3):
                        print(i * 3 + k, j * 3 + l)
                        li.append(board[i * 3 + k][j * 3 + l])
                for k in range(1, 10):
                    if li.count(str(k)) >= 2:
                        return False
        
        return True