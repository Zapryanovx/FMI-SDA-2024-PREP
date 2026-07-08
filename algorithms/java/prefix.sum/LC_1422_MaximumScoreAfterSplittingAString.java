// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/
package prefix.sum;

public class LC_1422_MaximumScoreAfterSplittingAString {
    public int maxScore(String s) {
        int maxScore = 0;

        int ones = 0;
        for (char ch: s.toCharArray()) {
            ones += ch == '1' ? 1 : 0;
        }

        int zeros = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '0') {
                zeros++;
            } else {
                ones--;
            }
            maxScore = Math.max(maxScore, zeros + ones);
        }

        return maxScore;
    }
}
