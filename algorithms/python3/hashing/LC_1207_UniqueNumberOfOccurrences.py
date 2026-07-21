# https://leetcode.com/problems/unique-number-of-occurrences/description

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        occs = {}

        for n in arr:
            occs[n] = occs.get(n, 0) + 1

        return len(set(occs.values())) == len(occs.values())