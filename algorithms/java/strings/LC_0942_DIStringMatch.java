// https://leetcode.com/problems/di-string-match/description/

public class LC_0942_DIStringMatch {
    public int[] diStringMatch(String s) {
        int low = 0;
        int high = s.length();

        int[] nums = new int[high + 1];
        int at = 0;

        for (char ch: s.toCharArray()) {
            if (ch == 'I') {
                nums[at++] = low;
                low++;
            } else {
                nums[at++] = high;
                high--;
            }
        }

        nums[at] = low;
        return nums;
    }
}
