// https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/

public class P2269_FindTheKBeautyOfANumber {
    public int divisorSubstrings(int num, int k) {
        String s = String.valueOf(num);
        int cnt = 0;

        for (int i = 0; i < s.length() - k + 1; i++) {
            int divisor = Integer.parseInt(s.substring(i, i + k));
            if (divisor == 0) {
                continue;
            }

            if (num % divisor == 0) {
                cnt++;
            }
        }

        return cnt;
    }
}
