// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

package binary.trees;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class LC_0637_AverageOfLevelsInBinaryTree {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> avgs = new ArrayList<>();
        Deque<TreeNode> d = new ArrayDeque<>();
        d.addLast(root);

        while (!d.isEmpty()) {
            long sum = 0;
            int cnt = d.size();

            for (int i = 0; i < cnt; i++) {
                TreeNode curr = d.pollFirst();
                sum += curr.val;

                if (curr.left != null) {
                    d.addLast(curr.left);
                }
                if (curr.right != null) {
                    d.addLast(curr.right);
                }

            }

            avgs.add((double) sum / cnt);
        }

        return avgs;
    }
}
