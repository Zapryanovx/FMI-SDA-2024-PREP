// https://leetcode.com/problems/pascals-triangle/description/

import java.util.ArrayList;
import java.util.List;

public class LC_0118_PascalsTriangle {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> rows = new ArrayList<>();

        rows.add(List.of(1));
        if (numRows == 1) {
            return rows;
        }

        rows.add(List.of(1, 1));
        if (numRows == 2) {
            return rows;
        }

        for (int i = 2; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();
            row.add(1);
            for (int j = 1; j < rows.size(); j++) {
                row.add(rows.get(i - 1).get(j - 1) + rows.get(i - 1).get(j));
            }
            row.add(1);
            rows.add(row);
        }

        return rows;
    }
}
