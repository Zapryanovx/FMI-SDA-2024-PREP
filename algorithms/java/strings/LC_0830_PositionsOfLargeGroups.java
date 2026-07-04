// https://leetcode.com/problems/positions-of-large-groups/description/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LC_0830_PositionsOfLargeGroups {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> groups = new ArrayList<>();
        int start = 0;

        for (int end = 1; end <= s.length(); end++) {
            if (end == s.length() || s.charAt(end) != s.charAt(start)) {
                if (end - start >= 3) {
                    groups.add(Arrays.asList(start, end - 1));
                }
                start = end;
            }
        }

        return groups;
    }
}
