# https://leetcode.com/problems/missing-number/description/

class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        nums.sort()

        left, right = 0, len(nums)

        while left < right:
            mid = (left + right) // 2
            if nums[mid] == mid:
                left = mid + 1
            else:
                right = mid

        return left