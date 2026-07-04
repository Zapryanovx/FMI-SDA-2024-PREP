// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/

public class P1876_SubstringsOfSizeThreeWithDistinctCharacters {
    public int countGoodSubstrings(String s) {
        if (s.length() < 3) {
            return 0;
        }

        int cnt = 0;
        for (int i = 0; i < s.length() - 2; i++) {
            if (s.charAt(i) != s.charAt(i + 1)
                    && s.charAt(i) != s.charAt(i + 2)
                    && s.charAt(i + 1) != s.charAt(i + 2)) {
                cnt++;
            }
        }
        return cnt;
    }
}
