// https://leetcode.com/problems/number-of-segments-in-a-string/description/

public class LC_0434_NumberOfSegmentsInAString {
    public int countSegments(String s) {
        if (s.isBlank()) {
            return 0;
        }
        return s.trim().split(" +").length;
    }
}
