// https://leetcode.com/problems/destination-city/description/
package hashing;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LC_01436_DestinationCity {
    public String destCity(List<List<String>> paths) {
        Set<String> out = new HashSet<>();
        Set<String> in = new HashSet<>();

        for (List<String> path: paths) {
            out.add(path.get(0));
            in.add(path.get(1));
        }

        for (String dest: in) {
            if (!out.contains(dest)) {
                return dest;
            }
        }
        return "";
    }
}
