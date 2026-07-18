# https://leetcode.com/problems/koko-eating-bananas/description/

class Solution:
    def check(self, piles: list[int], speed: int, h: int) -> bool:
        hours_used = 0
        for pile in piles:
            hours_used += math.ceil(pile / speed)
        return hours_used <= h

    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        left, right = 1, max(piles)

        while left < right:
            mid = (left + right) // 2
            if self.check(piles, mid, h):
                right = mid
            else:
                left = mid + 1

        return left