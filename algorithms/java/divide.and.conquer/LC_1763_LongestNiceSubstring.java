// https://leetcode.com/problems/longest-nice-substring/description/

public class LC_1763_LongestNiceSubstring {
    public String longestNiceSubstring(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (Character.isLowerCase(s.charAt(i)) && !s.contains(String.valueOf(Character.toUpperCase(s.charAt(i))))
                    || Character.isUpperCase(s.charAt(i)) && !s.contains(String.valueOf(Character.toLowerCase(s.charAt(i))))) {
                String left = longestNiceSubstring(s.substring(0, i));
                String right = longestNiceSubstring(s.substring(i + 1, s.length()));
                if(left.length() >= right.length()) {
                    return left;
                } else {
                    return right;
                }
            }
        }
        return s;
    }
}
