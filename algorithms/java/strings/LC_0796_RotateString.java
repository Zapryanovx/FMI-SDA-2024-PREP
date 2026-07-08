// https://leetcode.com/problems/rotate-string/description/
package strings;

public class LC_0796_RotateString {
    public boolean rotateString(String s, String goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == goal.charAt(0)) {
                if ((s.substring(i) + s.substring(0, i)).equals(goal)) {
                    return true;
                }
            }
        }

        return false;
    }
}
