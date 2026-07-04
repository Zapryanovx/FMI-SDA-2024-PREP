// https://leetcode.com/problems/climbing-stairs/description/

public class P0070_ClimbingStairs {
    public int climbStairs(int n) {
        int[] v = new int[n + 1];
        v[0] = 1;
        v[1] = 1;

        for (int i = 2; i <= n; i++) {
            v[i] = v[i - 1] + v[i - 2];
        }

        return v[n];
    }
}
