// https://leetcode.com/problems/find-common-characters/description/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class P1002_FindCommonCharacters {
    public List<String> commonChars(String[] words) {
        Map<Character, Integer> m = new HashMap<>();
        for (char ch: words[0].toCharArray()) {
            m.put(ch, m.getOrDefault(ch, 0) + 1);
        }

        for (String word: words) {
            Map<Character, Integer> l = new HashMap<>();
            for (char ch: word.toCharArray()) {
                l.put(ch, l.getOrDefault(ch, 0) + 1);
            }

            for (char ch: m.keySet()) {
                m.put(ch, Math.min(m.get(ch), l.getOrDefault(ch, 0)));
            }
        }

        List<String> inCommon = new ArrayList<>();
        for (char ch : m.keySet()) {
            for (int i = 0; i < m.get(ch); i++) {
                inCommon.add(String.valueOf(ch));
            }
        }
        return inCommon;
    }
}

