// https://leetcode.com/problems/isomorphic-strings/description/

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class LC_0205_IsomorphicStrings {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> sm = new HashMap<>();
        Map<Character, Integer> tm = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            if (!Objects.equals(sm.get(s.charAt(i)), tm.get(t.charAt(i)))) {
                return false;
            }

            sm.put(s.charAt(i), i);
            tm.put(t.charAt(i), i);
        }

        return true;
    }
}
