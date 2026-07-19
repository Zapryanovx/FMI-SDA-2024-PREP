// https://leetcode.com/problems/reverse-vowels-of-a-string/description

package strings;

import java.util.Set;

public class LC_0345_ReverseVowelsОfАString {
    public String reverseVowels(String s) {
        Set<Character> vowels = Set.of('A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u');
        StringBuilder sb = new StringBuilder(s);

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (vowels.contains(s.charAt(left)) && vowels.contains(s.charAt(right))) {
                char temp = sb.charAt(left);
                sb.setCharAt(left, sb.charAt(right));
                sb.setCharAt(right, temp);
                left++;
                right--;
            } else if (vowels.contains(s.charAt(left))) {
                right--;
            } else if (vowels.contains(s.charAt(right))) {
                left++;
            } else {
                left++;
                right--;
            }
        }

        return sb.toString();
    }
}
