// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

package binary.trees;

public class LC_0530_MinimumAbsoluteDifferenceInBST {
    private int prev = -1;
    private int minDiff = Integer.MAX_VALUE;

    public int getMinimumDifference(TreeNode root) {
        inOrder(root);
        return minDiff;
    }

    private void inOrder(TreeNode root) {
        if (root == null) {
            return;
        }

        inOrder(root.left);
        if (prev != -1) {
            minDiff = Math.min(minDiff, root.val - prev);
        }
        prev = root.val;
        inOrder(root.right);
    }
}
