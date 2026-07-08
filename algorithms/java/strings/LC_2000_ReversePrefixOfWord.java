// https://leetcode.com/problems/reverse-prefix-of-word/description/
package strings;

public class LC_2000_ReversePrefixOfWord {
    public String reversePrefix(String word, char ch) {
        int at = word.indexOf(ch);
        if (at == -1) {
            return word;
        }

        String reversedPrefix = new StringBuilder(word.substring(0, at + 1)).reverse().toString();
        String suffix = word.substring(at + 1, word.length());
        return reversedPrefix + suffix;
    }
}
