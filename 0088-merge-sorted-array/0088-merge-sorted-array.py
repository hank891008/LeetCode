class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        num = []
        i, j = 0, 0
        while i < m or j < n:
            if i == m:
                num.append(nums2[j])
                j += 1
            elif j == n:
                num.append(nums1[i])
                i += 1
            else:
                if nums1[i] >= nums2[j]:
                    num.append(nums2[j])
                    j += 1
                else:
                    num.append(nums1[i])
                    i += 1
        for i in range(len(num)):
            nums1[i] = num[i]