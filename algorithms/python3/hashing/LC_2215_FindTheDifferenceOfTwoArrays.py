# https://leetcode.com/problems/find-the-difference-of-two-arrays/description

class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        distinct_of_nums1 = set()
        distinct_of_nums2 = set()

        for n in nums1:
            distinct_of_nums1.add(n)

        for n in nums2:
            distinct_of_nums2.add(n)
            distinct_of_nums1.discard(n)

        for n in nums1:
            distinct_of_nums2.discard(n)

        return [list(distinct_of_nums1), list(distinct_of_nums2)]