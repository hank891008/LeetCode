class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        max_sum = math.inf
        ret = []
        for i in range(len(list1)):
            try:
                j = list2.index(list1[i])
                if i + j < max_sum:
                    ret.clear()
                    max_sum = i + j
                if i + j == max_sum:
                    ret.append(list1[i])
            except:
                continue
        return ret