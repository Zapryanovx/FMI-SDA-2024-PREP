// https://leetcode.com/problems/valid-palindrome/description/

public class P0125_ValidPalindrome {
    public boolean isPalindrome(String s) {
        char[] charArray = s.toCharArray();
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (Character.isDigit(charArray[left]) && Character.isDigit(charArray[right])) {
                if (charArray[left] != charArray[right]) {
                    return false;
                }
                left++;
                right--;
            } else if (Character.isLetter(charArray[left]) && Character.isLetter(charArray[right])) {
                if (Character.toLowerCase(charArray[left]) != Character.toLowerCase(charArray[right])) {
                    return false;
                }
                left++;
                right--;
            } else if (!Character.isLetterOrDigit(charArray[left])) {
                left++;
            } else if (!Character.isLetterOrDigit(charArray[right])) {
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
}
