// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

package binary.trees;

public class LC_0104_MaximumDepthOfBinaryTree {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        return Math.max(1 + maxDepth(root.left), 1 + maxDepth(root.right));
    }
}
