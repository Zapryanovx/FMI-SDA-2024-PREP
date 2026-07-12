// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

package binary.trees;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class LC_0102_BinaryTreeLevelOrderTraversal {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) {
            return List.of();
        }

        List<List<Integer>> result = new ArrayList<>();
        Deque<TreeNode> levels = new ArrayDeque<>();
        levels.addLast(root);

        while (!levels.isEmpty()) {
            int levelSize = levels.size();
            List<Integer> currLevel = new ArrayList<>();

            for (int i = 0; i < levelSize; i++) {
                TreeNode curr = levels.pollFirst();
                currLevel.add(curr.val);
                if (curr.left != null) {
                    levels.addLast(curr.left);
                }

                if (curr.right != null) {
                    levels.addLast(curr.right);
                }
            }

            result.add(currLevel);
        }

        return result;
    }
}
