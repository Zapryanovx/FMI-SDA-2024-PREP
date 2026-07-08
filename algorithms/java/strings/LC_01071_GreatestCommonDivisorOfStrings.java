// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
package strings;

public class LC_01071_GreatestCommonDivisorOfStrings {
    public String gcdOfStrings(String str1, String str2) {
        StringBuilder gcd;
        if (str1.length() <= str2.length()) {
            gcd = new StringBuilder(str1);
        } else {
            gcd = new StringBuilder(str2);
        }

        while (!gcd.isEmpty()) {
            if (str1.length() % gcd.length() == 0 && str2.length() % gcd.length() == 0
                    && gcd.toString().repeat(str1.length() / gcd.length()).equals(str1)
                    && gcd.toString().repeat(str2.length() / gcd.length()).equals(str2)) {
                break;
            }
            gcd.deleteCharAt(gcd.length() - 1);
        }

        return gcd.toString();
    }
}
