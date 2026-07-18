// https://leetcode.com/problems/find-bottom-left-tree-value/description/

package binary.trees;

public class LC_0513_FindBottomLeftTreeValue {
    private int maxDepth = -1;
    private int result;

    public int findBottomLeftValue(TreeNode root) {
        dfs(root, 0);
        return result;
    }

    private void dfs(TreeNode root, int depth) {
        if (root == null) {
            return;
        }

        if (depth > maxDepth) {
            maxDepth = depth;
            result = root.val;
        }

        dfs(root.left, depth + 1);
        dfs(root.right, depth + 1);
    }
}
