// https://leetcode.com/problems/assign-cookies/description/

import java.util.Arrays;

public class LC_0455_AssignCookies {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int gRight = g.length - 1;
        int sRight = s.length - 1;

        while (sRight >= 0 && gRight >= 0) {
            if (s[sRight] >= g[gRight]) {
                sRight--;
            }
            gRight--;
        }
        return s.length - sRight - 1;
    }
}
