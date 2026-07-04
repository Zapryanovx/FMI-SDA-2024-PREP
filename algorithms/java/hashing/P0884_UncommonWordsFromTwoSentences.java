// https://leetcode.com/problems/uncommon-words-from-two-sentences/description/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class P0884_UncommonWordsFromTwoSentences {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> m = new HashMap<>();

        for (String s: s1.split(" ")) {
            m.put(s, m.getOrDefault(s, 0) + 1);
        }

        for (String s: s2.split(" ")) {
            m.put(s, m.getOrDefault(s, 0) + 1);
        }

        List<String> l = new ArrayList<>();
        for (Map.Entry<String, Integer> entry: m.entrySet()) {
            if (entry.getValue() == 1) {
                l.add(entry.getKey());
            }
        }
        return l.toArray(new String[0]);
    }
}
