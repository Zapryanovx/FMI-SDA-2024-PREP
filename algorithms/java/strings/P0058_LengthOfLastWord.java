// https://leetcode.com/problems/length-of-last-word/description/

public class P0058_LengthOfLastWord {
    public int lengthOfLastWord(String s) {
        String[] words = s.split(" ");
        return words[words.length - 1].length();
    }
}
