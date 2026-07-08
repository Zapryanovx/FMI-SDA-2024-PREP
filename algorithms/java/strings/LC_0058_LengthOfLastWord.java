// https://leetcode.com/problems/length-of-last-word/description/
package strings;

public class LC_0058_LengthOfLastWord {
    public int lengthOfLastWord(String s) {
        String[] words = s.split(" ");
        return words[words.length - 1].length();
    }
}
