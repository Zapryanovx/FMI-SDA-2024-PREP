// https://leetcode.com/problems/string-compression/description

package strings;

public class LC_0443_StringCompression {
    public int compress(char[] chars) {
        int curr = 1;
        int at = 0;

        for (int i = 1; i < chars.length; i++) {
            if (chars[i] != chars[i - 1]) {
                chars[at++] = chars[i - 1];
                if (curr > 1) {
                    for (char digit : String.valueOf(curr).toCharArray()) {
                        chars[at++] = digit;
                    }
                }
                curr = 1;
            } else {
                curr++;
            }
        }

        chars[at++] = chars[chars.length - 1];
        if (curr > 1) {
            for (char digit : String.valueOf(curr).toCharArray()) {
                chars[at++] = digit;
            }
        }

        return at;
    }
}
