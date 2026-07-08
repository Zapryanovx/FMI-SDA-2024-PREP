// https://leetcode.com/problems/number-of-lines-to-write-string/description/
package strings;

public class LC_0806_NumberOfLinesToWriteString {
    public int[] numberOfLines(int[] widths, String s) {
        int cnt = 1;
        int sum = 0;

        for (char ch: s.toCharArray()) {
            if (sum + widths[ch - 'a'] > 100) {
                cnt++;
                sum = 0;
            }
            sum += widths[ch - 'a'];
        }

        return new int[]{cnt, sum};
    }
}
