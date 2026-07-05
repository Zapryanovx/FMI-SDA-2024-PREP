// https://leetcode.com/problems/path-sum/description/

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class LC_0112_PathSum {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return checkIfHasPathSum(root, targetSum, 0);
    }

    private boolean checkIfHasPathSum(TreeNode root, int targetSum, int currSum) {
        if (root == null) {
            return false;
        }

        if (currSum + root.val == targetSum && root.left == null && root.right == null) {
            return true;
        }

        return checkIfHasPathSum(root.left, targetSum, currSum + root.val)
                || checkIfHasPathSum(root.right, targetSum, currSum + root.val);
    }
}
