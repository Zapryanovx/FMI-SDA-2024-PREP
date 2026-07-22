# https://leetcode.com/problems/max-number-of-k-sum-pairs/description

class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()

        l = 0
        r = len(nums) - 1
        cnt = 0

        while l < r:
            pair = nums[l] + nums[r]
            if pair == k:
                cnt += 1
                l += 1
                r -= 1
            elif pair < k:
                l += 1
            else:
                r -= 1

        return cnt