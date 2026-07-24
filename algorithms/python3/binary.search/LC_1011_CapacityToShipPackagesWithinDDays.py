# https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution:
    def check(self, weights: list[int], capacity: int, days: int) -> bool:
        days_used = 1
        current_load = 0
        for w in weights:
            if current_load + w > capacity:
                days_used += 1
                current_load = 0
            current_load += w
        return days_used <= days

    def shipWithinDays(self, weights: list[int], days: int) -> int:
        left, right = max(weights), sum(weights)

        while left < right:
            mid = (left + right) // 2
            if self.check(weights, mid, days):
                right = mid
            else:
                left = mid + 1

        return left