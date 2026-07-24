# https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.max_length = 0
        self.dfs(root)
        return self.max_length

    def dfs(self, root):
        if root is None:
            return

        self.dfs2(root.left, 1, 0)
        self.dfs2(root.right, 0, 0)

    def dfs2(self, node, direction, currLength):
        if node is None:
            self.max_length = max(self.max_length, currLength)
            return

        if direction == 0:
            self.dfs2(node.left, 1, currLength + 1)
            self.dfs2(node.right, 0, 0)
        else:
            self.dfs2(node.right, 0, currLength + 1)
            self.dfs2(node.left, 1, 0)
