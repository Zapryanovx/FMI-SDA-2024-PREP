// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Set;

public class LC_0150_EvaluateReversePolishNotation {
    public int evalRPN(String[] tokens) {
        Set<String> s = Set.of("+", "-", "*", "/");
        Deque<Integer> d = new ArrayDeque<>();

        for (String t: tokens) {
            if (s.contains(t)) {
                int right = d.pollLast();
                int left = d.pollLast();

                if (t.equals("+")) {
                    d.add(left + right);
                } else if (t.equals("-")) {
                    d.add(left - right);
                } else if (t.equals("*")) {
                    d.add(left * right);
                } else {
                    d.add(left / right);
                }
            } else {
                d.add(Integer.parseInt(t));
            }
        }

        return d.peek();
    }
}
