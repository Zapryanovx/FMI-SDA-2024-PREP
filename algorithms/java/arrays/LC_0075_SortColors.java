// https://leetcode.com/problems/sort-colors/description/

public class LC_0075_SortColors {
    public void sortColors(int[] nums) {
        int[] histogram = new int[3];
        for (int n : nums) {
            histogram[n]++;
        }

        int[] prefix = new int[3];
        prefix[0] = histogram[0];
        for (int h = 1; h < 3; h++) {
            prefix[h] = prefix[h - 1] + histogram[h];
        }

        int color = 0;
        int i = 0;
        while (i < nums.length) {
            while (i < prefix[color]) {
                nums[i++] = color;
            }
            color++;
        }
    }
}
