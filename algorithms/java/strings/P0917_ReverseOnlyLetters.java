// https://leetcode.com/problems/reverse-only-letters/description/

public class P0917_ReverseOnlyLetters {
    public String reverseOnlyLetters(String s) {
        StringBuilder sb = new StringBuilder(s);

        int left = 0;
        int right = s.length() - 1;

        while (left <= right) {
            if (Character.isLetter(sb.charAt(left))
                    && Character.isLetter(sb.charAt(right))) {
                char temp = sb.charAt(left);
                sb.setCharAt(left, sb.charAt(right));
                sb.setCharAt(right, temp);
                left++;
                right--;
            } else if (!Character.isLetter(sb.charAt(left))) {
                left++;
            } else if (!Character.isLetter(sb.charAt(right))) {
                right--;
            }
        }

        return sb.toString();
    }
}
