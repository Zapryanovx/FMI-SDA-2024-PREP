// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
package strings;

public class LC_01614_MaximumNestingDepthOfTheParentheses {
    public int maxDepth(String s) {
        int open = 0;
        int closed = 0;

        int maxDepth = 0;
        for (char ch: s.toCharArray()) {
            if (ch == '(') {
                open++;
            } else if (ch == ')') {
                closed++;
            }

            maxDepth = Math.max(maxDepth, open - closed);
        }

        return maxDepth;
    }
}
