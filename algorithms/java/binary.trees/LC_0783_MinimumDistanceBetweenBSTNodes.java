// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

package binary.trees;

public class LC_0783_MinimumDistanceBetweenBSTNodes {
    private int prev = -1;
    private int diff = Integer.MAX_VALUE;

    public int minDiffInBST(TreeNode root) {
        if (root == null) {
            return Integer.MAX_VALUE;
        }

        minDiffInBST(root.left);
        if (prev != -1) {
            diff = Math.min(diff, Math.abs(root.val - prev));
        }
        prev = root.val;
        minDiffInBST(root.right);
        return diff;
    }
}
