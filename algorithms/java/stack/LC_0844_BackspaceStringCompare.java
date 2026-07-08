// https://leetcode.com/problems/backspace-string-compare/description/
package stack;

import java.util.ArrayDeque;
import java.util.Deque;

public class LC_0844_BackspaceStringCompare {
    public boolean backspaceCompare(String s, String t) {
        Deque<Character> ss = new ArrayDeque<>();
        Deque<Character> ts = new ArrayDeque<>();

        for (char ch: s.toCharArray()) {
            if (ch == '#') {
                if (!ss.isEmpty()) {
                    ss.removeLast();
                }
                continue;
            }
            ss.addLast(ch);
        }

        for (char ch: t.toCharArray()) {
            if (ch == '#') {
                if (!ts.isEmpty()) {
                    ts.removeLast();
                }
                continue;
            }
            ts.addLast(ch);
        }

        if (ss.size() != ts.size()) {
            return false;
        }

        while (!ss.isEmpty()) {
            char sEl = ss.removeLast();
            char tEl = ts.removeLast();
            if (sEl != tEl) {
                return false;
            }
        }
        return true;
    }
}
