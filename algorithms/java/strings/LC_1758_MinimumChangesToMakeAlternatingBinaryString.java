// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/
package strings;

public class LC_1758_MinimumChangesToMakeAlternatingBinaryString {
    public int minOperations(String s) {
        if (s.length() == 1) {
            return 0;
        }

        int count0 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) - '0' != i % 2) {
                count0++;
            }
        }
        return Math.min(count0, s.length() - count0);
    }
}
