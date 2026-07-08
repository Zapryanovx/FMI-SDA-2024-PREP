// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/
package strings;

public class LC_1662_CheckIfTwoStringArraysAreEquivalent {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        for (String word: word1) {
            s1.append(word);
        }

        for (String word: word2) {
            s2.append(word);
        }

        return s1.toString().equals(s2.toString());
    }
}
