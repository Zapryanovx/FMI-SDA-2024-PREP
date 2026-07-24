# https://leetcode.com/problems/count-good-nodes-in-binary-tree/description

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def goodNodes(self, root: TreeNode) -> int:
        self.cnt = 0
        self.dfs(root, root.val)
        return self.cnt

    def dfs(self, root: TreeNode, max_so_far: int):
        if root is None:
            return

        if root.val >= max_so_far:
            self.cnt += 1

        self.dfs(root.left, max(root.val, max_so_far))
        self.dfs(root.right, max(root.val, max_so_far))