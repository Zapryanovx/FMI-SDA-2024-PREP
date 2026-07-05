// https://leetcode.com/problems/baseball-game/description/

import java.util.ArrayDeque;
import java.util.Deque;

public class LC_0682_BaseballGame {
    public int calPoints(String[] operations) {
        Deque<String> d = new ArrayDeque<>();

        for (String op: operations) {
            if (op.charAt(0) == '+') {
                int right = Integer.parseInt(d.pollLast());
                int left = Integer.parseInt(d.peekLast());
                d.add(String.valueOf(right));
                d.add(String.valueOf(left + right));
            } else if (op.charAt(0) == 'D') {
                int top = Integer.parseInt(d.peekLast());
                d.add(String.valueOf(top * 2));
            } else if (op.charAt(0) == 'C') {
                d.pollLast();
            } else {
                d.add(op);
            }
        }

        int sum = 0;
        while (!d.isEmpty()) {
            sum += Integer.parseInt(d.pollLast());
        }
        return sum;
    }
}
