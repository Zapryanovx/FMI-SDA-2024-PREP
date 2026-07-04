// https://leetcode.com/problems/path-crossing/description/

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LC_1496_PathCrossing {
    public boolean isPathCrossing(String path) {
        Set<List<Integer>> coords = new HashSet<>();
        int x = 0;
        int y = 0;
        coords.add(List.of(x, y));

        for (char ch : path.toCharArray()) {
            if (ch == 'N') {
                y++;
            } else if (ch == 'S') {
                y--;
            } else if (ch == 'E') {
                x++;
            } else {
                x--;
            }

            List<Integer> pos = List.of(x, y);
            if (coords.contains(pos)) {
                return true;
            }
            coords.add(pos);
        }

        return false;
    }
}
