# https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution:
    def check(
            self,
            bloomDay: List[int],
            mid: int,
            m: int,
            k: int
    ) -> bool:

        currFlowers = 0
        currBouquets = 0

        for day in bloomDay:
            if day <= mid:
                currFlowers += 1

                if currFlowers == k:
                    currBouquets += 1
                    currFlowers = 0
            else:
                currFlowers = 0

        return currBouquets >= m

    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if m * k > len(bloomDay):
            return -1

        left = min(bloomDay)
        right = max(bloomDay)

        ans = right

        while left <= right:
            mid = left + (right - left) // 2

            if self.check(bloomDay, mid, m, k):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans