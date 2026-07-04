// https://leetcode.com/problems/valid-anagram/description/

import java.util.HashMap;
import java.util.Map;

public class LC_0242_ValidAnagram {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> sm = new HashMap<>();
        Map<Character, Integer> tm = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            sm.put(s.charAt(i), sm.getOrDefault(s.charAt(i), 0) + 1);
            tm.put(t.charAt(i), tm.getOrDefault(t.charAt(i), 0) + 1);
        }

        for (char ch: sm.keySet()) {
            if (!sm.get(ch).equals(tm.getOrDefault(ch, -1))) {
                return false;
            }
        }

        return true;
    }
}
