// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/

public class LC_1295_FindNumbersWithEvenNumberOfDigits {
    public int findNumbers(int[] nums) {
        int cnt = 0;
        for (int num : nums) {
            int numDigits = String.valueOf(num).length();
            if (numDigits % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
}
