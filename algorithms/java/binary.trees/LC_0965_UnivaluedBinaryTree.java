// https://leetcode.com/problems/univalued-binary-tree/description/

package binary.trees;

public class LC_0965_UnivaluedBinaryTree {
    private int node = -1;

    public boolean isUnivalTree(TreeNode root) {
        if (root == null) {
            return true;
        }

        if (node == -1) {
            node = root.val;
        }

        if (node != root.val) {
            return false;
        }

        return isUnivalTree(root.left) && isUnivalTree(root.right);
    }
}
