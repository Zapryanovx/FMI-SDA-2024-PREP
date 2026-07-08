// https://leetcode.com/problems/consecutive-characters/description/
package strings;

public class LC_1446_ConsecutiveCharacters {
    public int maxPower(String s) {
        int maxLength = Integer.MIN_VALUE;
        int start = 0;

        for (int end = 1; end <= s.length(); end++) {
            if (end == s.length() || s.charAt(end) != s.charAt(start)) {
                maxLength = Math.max(maxLength, end - start);
                start = end;
            }
        }

        return maxLength;
    }
}
