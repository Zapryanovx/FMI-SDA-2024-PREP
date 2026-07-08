// https://leetcode.com/problems/valid-parentheses/description/
package stack;

import java.util.ArrayDeque;
import java.util.Deque;

public class LC_0020_ValidParentheses {
    public boolean isValid(String s) {
        Deque<Character> d = new ArrayDeque<>();

        for (char ch: s.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[') {
                d.add(ch);
            } else if (d.isEmpty()) {
                return false;
            } else {
                char opening = d.peekLast();
                if (ch == ')' && opening != '(') {
                    return false;
                } else if (ch == ']' && opening != '[') {
                    return false;
                } else if (ch == '}' && opening != '{') {
                    return false;
                }
                d.pollLast();
            }
        }

        return d.isEmpty();
    }
}
