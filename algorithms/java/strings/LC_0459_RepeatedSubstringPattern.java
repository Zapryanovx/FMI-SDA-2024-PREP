// https://leetcode.com/problems/repeated-substring-pattern/description/

public class LC_0459_RepeatedSubstringPattern {
    public boolean repeatedSubstringPattern(String s) {
        StringBuilder substr = new StringBuilder();
        for (int i = 0; i < s.length() / 2; i++) {
            substr.append(s.charAt(i));
            if (s.equals(substr.toString().repeat(s.length() / substr.length()))) {
                return true;
            }
        }
        return false;
    }
}
