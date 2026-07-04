// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

public class P0557_ReverseWordsInAStringIII {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        for (int i = 0; i < words.length; i++) {
            words[i] = new StringBuilder(words[i]).reverse().toString();
        }
        return String.join(" ", words);
    }
}
