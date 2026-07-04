// https://leetcode.com/problems/most-common-word/description/

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class P0819_MostCommonWord {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> s = Arrays.stream(banned).collect(Collectors.toSet());
        Map<String, Integer> m = new HashMap<>();

        String[] words = paragraph.split("[!?',;. ]+");
        int maxFreq = 0;
        for (String word: words) {
            String lower = word.toLowerCase();
            if (s.contains(lower)) {
                continue;
            }
            m.put(lower, m.getOrDefault(lower, 0) + 1);
            maxFreq = Math.max(maxFreq, m.get(lower));
        }

        for (Map.Entry<String, Integer> entry: m.entrySet()) {
            if (entry.getValue() == maxFreq) {
                return entry.getKey();
            }
        }

        return "";
    }
}
