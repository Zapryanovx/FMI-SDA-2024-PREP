// https://leetcode.com/problems/counting-bits/description/

public class P0338_CountingBits {
    public int[] countBits(int n) {
        int[] ones = new int[n + 1];
        ones[0] = 0;

        for (int i = 1; i <= n; i++) {
            ones[i] = ones[i >> 1] + i % 2;
        }

        return ones;
    }
}
