# https://leetcode.com/problems/equal-row-and-column-pairs/description

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        row_counts = Counter(tuple(row) for row in grid)
        transposed = zip(*grid)
        return sum(row_counts[col] for col in transposed)