// https://leetcode.com/problems/diameter-of-binary-tree/description/

package binary.trees;

public class LC_0543_DiameterOfBinaryTree {
    private int length = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        maxDepth(root);
        return length;
    }

    private int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        length = Math.max(length, left + right);
        return 1 + Math.max(left, right);
    }
}
