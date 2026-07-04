// https://leetcode.com/problems/robot-return-to-origin/description/

public class LC_0657_RobotReturnToOrigin {
    public boolean judgeCircle(String moves) {
        int vertical = 0;
        int horizontal = 0;

        for (char ch: moves.toCharArray()) {
            if (ch == 'U') {
                vertical++;
            } else if (ch == 'D') {
                vertical--;
            } else if (ch == 'R') {
                horizontal++;
            } else if (ch == 'L') {
                horizontal--;
            }
        }

        return vertical == 0 && horizontal == 0;
    }
}
