// https://leetcode.com/problems/license-key-formatting/description/

public class LC_0482_LicenseKeyFormatting {
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder formatted = new StringBuilder();
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '-') {
                continue;
            }

            if (count > 0 && count % k == 0) {
                formatted.append('-');
            }
            formatted.append(Character.toUpperCase(s.charAt(i)));
            count++;
        }
        return formatted.reverse().toString();
    }
}
