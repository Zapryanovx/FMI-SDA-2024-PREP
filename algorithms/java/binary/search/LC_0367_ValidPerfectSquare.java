// https://leetcode.com/problems/valid-perfect-square/description/

package binary.search;

public class LC_0367_ValidPerfectSquare {
    public boolean isPerfectSquare(int num) {
        long l = 0;
        long r = num;

        while (l <= r) {
            long m = l + (r - l) / 2;
            if (m * m == num) {
                return true;
            } else if (m * m > num) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return false;
    }
}
