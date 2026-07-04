// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/

public class P2108_FindFirstPalindromicStringInTheArray {
    public String firstPalindrome(String[] words) {
        for (String s: words) {
            if (isPalindrome(s)) {
                return s;
            }
        }
        return "";
    }

    private boolean isPalindrome(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }
}
