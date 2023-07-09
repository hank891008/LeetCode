class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        ret = ["Both", "Bulky", "Heavy", "Neither"]
        flag = [0, 0]
        if length >= 1e4 or width >= 1e4 or height >= 1e4 or length * width * height >= 1e9:
            flag[0] = 1
        if mass >= 100:
            flag[1] = 1
        print(flag)
        if flag[0] + flag[1] == 0:
            return ret[3]
        elif flag[0] + flag[1] == 1:
            return ret[flag[0] + 2 * flag[1]]
        else:
            return ret[0]
        