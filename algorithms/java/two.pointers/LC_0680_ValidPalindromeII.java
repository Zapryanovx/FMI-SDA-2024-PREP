// https://leetcode.com/problems/valid-palindrome-ii/description/
package two.pointers;

public class LC_0680_ValidPalindromeII {
    public boolean validPalindrome(String s) {
        char[] charArray = s.toCharArray();
        int left = 0;
        int right = charArray.length - 1;

        while (left < right) {
            if (charArray[left] != charArray[right]) {
                return isPalindrome(charArray, left + 1, right)
                        || isPalindrome(charArray, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }

    private boolean isPalindrome(char[] charArray, int left, int right) {
        while (left < right) {
            if (charArray[left] != charArray[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
