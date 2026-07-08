// https://leetcode.com/problems/defuse-the-bomb/description/
package sliding.window;

public class LC_1652_DefuseTheBomb {
    public int[] decrypt(int[] code, int k) {
        int[] result = new int[code.length];
        if ( k == 0) {
            return result;
        }

        for (int i = 0; i < code.length; i++) {
            if (k > 0) {
                if (i + k < code.length) {
                    result[i] = sumRange(code, i + 1, i + k + 1);
                } else {
                    result[i] = sumRange(code, i + 1, code.length) + sumRange(code, 0, k - (code.length - i - 1));
                }
            } else {
                if (i + k >= 0) {
                    result[i] = sumRange(code, i + k, i);
                } else {
                    result[i] = sumRange(code, 0, i) + sumRange(code, code.length - (-k - i), code.length);
                }
            }
        }
        return result;
    }

    private int sumRange(int[] code, int from, int to) {
        int sum = 0;
        for (int j = from; j < to; j++) {
            sum += code[j];
        }
        return sum;
    }
}
