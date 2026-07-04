// https://leetcode.com/problems/score-of-a-string/description/

public class P3110_ScoreOfAString {
    public int scoreOfString(String s) {
        int score = 0;

        for (int i = 1; i < s.length(); i++) {
            score += Math.abs(s.charAt(i) - s.charAt(i - 1));
        }

        return score;
    }
}
