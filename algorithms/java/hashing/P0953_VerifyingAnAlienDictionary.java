// https://leetcode.com/problems/verifying-an-alien-dictionary/description/

import java.util.HashMap;
import java.util.Map;

public class P0953_VerifyingAnAlienDictionary {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> m = new HashMap<>();

        for (int i = 0; i < order.length(); i++) {
            m.put(order.charAt(i), i);
        }

        for (int j = 1; j < words.length; j++) {
            String prev = words[j - 1];
            String curr = words[j];
            int minLength = Math.min(prev.length(), curr.length());
            boolean foundDiff = false;

            for (int i = 0; i < minLength; i++) {
                char c1 = curr.charAt(i);
                char c2 = prev.charAt(i);
                if (c1 != c2) {
                    if (m.get(c1) < m.get(c2)) {
                        return false;
                    }
                    foundDiff = true;
                    break;
                }
            }

            if (!foundDiff && prev.length() > curr.length()) {
                return false;
            }
        }

        return true;
    }
}
