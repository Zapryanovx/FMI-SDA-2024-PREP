// https://leetcode.com/problems/sqrtx/description/

package binary.search;

public class LC_0069_SqrtOfX {
    public int mySqrt(int x) {
        int l = 0;
        int r = x / 2 + 1;
        int res = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if ((long) m * m > x) {
                r = m - 1;
            } else {
                res = m;
                l = m + 1;
            }
        }

        return res;
    }
}
