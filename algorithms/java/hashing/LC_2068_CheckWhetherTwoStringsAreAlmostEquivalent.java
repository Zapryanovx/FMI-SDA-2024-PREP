// https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/description/

import java.util.HashMap;
import java.util.Map;

public class LC_2068_CheckWhetherTwoStringsAreAlmostEquivalent {
    public boolean checkAlmostEquivalent(String word1, String word2) {
        Map<Character, Integer> m = new HashMap<>();

        for (char ch: word1.toCharArray()) {
            m.put(ch, m.getOrDefault(ch, 0) + 1);
        }

        for (char ch: word2.toCharArray()) {
            m.put(ch, m.getOrDefault(ch, 0) - 1);
        }

        for (int cnt : m.values()) {
            if (Math.abs(cnt) > 3) {
                return false;
            }
        }

        return true;
    }
}
