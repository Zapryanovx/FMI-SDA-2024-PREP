# https://leetcode.com/problems/find-pivot-index/description

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        left = 0

        for i in range(0, len(nums)):
            if left == total - left - nums[i]:
                return i

            left += nums[i]

        return -1
