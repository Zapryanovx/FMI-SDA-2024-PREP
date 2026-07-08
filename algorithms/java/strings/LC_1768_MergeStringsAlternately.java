// https://leetcode.com/problems/merge-strings-alternately/description/
package strings;

public class LC_1768_MergeStringsAlternately {
    public String mergeAlternately(String word1, String word2) {
        char[] charArray = new char[word1.length() + word2.length()];

        int word1Index = 0;
        int word2Index = 0;
        int at = 0;

        while (word1Index < word1.length() && word2Index < word2.length()) {
            charArray[at++] = word1.charAt(word1Index++);
            charArray[at++] = word2.charAt(word2Index++);
        }

        while (word1Index < word1.length()) {
            charArray[at++] = word1.charAt(word1Index++);
        }

        while (word2Index < word2.length()) {
            charArray[at++] = word2.charAt(word2Index++);
        }

        return String.valueOf(charArray);
    }
}
