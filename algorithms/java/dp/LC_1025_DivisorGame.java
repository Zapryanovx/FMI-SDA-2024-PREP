// https://leetcode.com/problems/divisor-game/description/
package dp;

public class LC_1025_DivisorGame {
    public boolean divisorGame(int n) {
        boolean[] win = new boolean[n + 1];
        win[0] = false;
        win[1] = false;

        for (int i = 2; i <= n; i++) {
            for (int x = 1; x < i; x++) {
                if (i % x == 0 && !win[i - x]) {
                    win[i] = true;
                    break;
                }
            }
        }

        return win[n];
    }
}
