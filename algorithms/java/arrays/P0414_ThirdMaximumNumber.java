// https://leetcode.com/problems/third-maximum-number/description/

public class P0414_ThirdMaximumNumber {
    public int thirdMax(int[] nums) {
        long first = nums[0];
        long second = Long.MIN_VALUE;
        long third = Long.MIN_VALUE;

        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;

            } else if (num > second && num != first) {
                third = second;
                second = num;
            } else if (num > third && num != first && num != second) {
                third = num;
            }
        }
        return (third == Long.MIN_VALUE) ? (int) first : (int) third;
    }
}
