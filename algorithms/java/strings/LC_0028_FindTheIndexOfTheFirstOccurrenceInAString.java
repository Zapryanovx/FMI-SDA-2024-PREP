// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

public class LC_0028_FindTheIndexOfTheFirstOccurrenceInAString {
    public int strStr(String haystack, String needle) {
        int windowSize = needle.length();
        for (int i = 0; i <= haystack.length() - windowSize; i++) {
            if (check(haystack, needle, i, i + windowSize)) {
                return i;
            }
        }
        return -1;
    }

    private boolean check(String haystack, String needle, int from, int to) {
        int at = 0;
        for (int i = from; i < to; i++) {
            if (haystack.charAt(i) != needle.charAt(at++)) {
                return false;
            }
        }
        return true;
    }
}
