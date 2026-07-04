// https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/

public class LC_2264_Largest3SameDigitNumberInString {
    public String largestGoodInteger(String num) {
        String maximumGood = "";

        for (int i = 0; i < num.length() - 2; i++) {
            if (num.charAt(i) == num.charAt(i + 1)
                    && num.charAt(i + 1) == num.charAt(i + 2)) {
                if (maximumGood.isEmpty()
                        || num.charAt(i) > maximumGood.charAt(0)) {
                    maximumGood = num.substring(i, i + 3);
                }
            }
        }

        return maximumGood;
    }
}
