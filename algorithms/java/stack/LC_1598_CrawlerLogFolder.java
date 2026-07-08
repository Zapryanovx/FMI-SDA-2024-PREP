// https://leetcode.com/problems/crawler-log-folder/description/
package stack;

import java.util.ArrayDeque;
import java.util.Deque;

public class LC_1598_CrawlerLogFolder {
    public int minOperations(String[] logs) {
        Deque<String> d = new ArrayDeque<>();
        for (String s: logs) {
            if (s.equals("./")) {
                continue;
            } else if (s.equals("../")) {
                d.pollLast();
            } else {
                d.add(s);
            }
        }
        return d.size();
    }
}
