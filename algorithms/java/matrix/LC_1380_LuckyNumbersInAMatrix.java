// https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
package matrix;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LC_1380_LuckyNumbersInAMatrix {
    public List<Integer> luckyNumbers(int[][] matrix) {
        Set<Integer> sMin = new HashSet<>();
        for (int[] ints : matrix) {
            int min = Integer.MAX_VALUE;
            for (int col = 0; col < matrix[0].length; col++) {
                min = Math.min(min, ints[col]);
            }
            sMin.add(min);
        }

        Set<Integer> sMax = new HashSet<>();
        for (int col = 0; col < matrix[0].length; col++) {
            int max = Integer.MIN_VALUE;
            for (int[] ints : matrix) {
                max = Math.max(max, ints[col]);
            }
            sMax.add(max);
        }

        List<Integer> res = new ArrayList<>();
        for (int el: sMin) {
            if (sMax.contains(el)) {
                res.add(el);
            }
        }
        return res;
    }
}
