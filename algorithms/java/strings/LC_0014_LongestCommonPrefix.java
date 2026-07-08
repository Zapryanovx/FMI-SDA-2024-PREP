// https://leetcode.com/problems/longest-common-prefix/description/
package strings;

public class LC_0014_LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        int minLength = Integer.MAX_VALUE;
        for (String str : strs) {
            minLength = Math.min(minLength, str.length());
        }

        int end = -1;
        for (int i = 0; i < minLength; i++) {
            boolean isMatch = true;
            for (int j = 1; j < strs.length; j++) {
                if (strs[j].charAt(i) != strs[j - 1].charAt(i)) {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch) {
                end = i;
            } else {
                break;
            }
        }
        return strs[0].substring(0, end + 1);
    }
}
