// https://leetcode.com/problems/roman-to-integer/description/

import java.util.HashMap;
import java.util.Map;

public class LC_0013_RomanToInteger {
    public int romanToInt(String s) {
        Map<Character, Integer> m = new HashMap<>(Map.of(
                'I', 1,
                'V', 5,
                'X', 10,
                'L', 50,
                'C', 100,
                'D', 500,
                'M', 1000
        ));

        int n = 0;
        int i = 0;
        while (i < s.length()) {
            char ch = s.charAt(i);
            if (i < s.length() - 1 && m.get(s.charAt(i)) < m.get(s.charAt(i + 1))) {
                n -= m.get(s.charAt(i));
            } else {
                n += m.get(s.charAt(i));
            }
            i++;
        }

        return n;
    }
}
