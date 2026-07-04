// https://leetcode.com/problems/remove-element/

public class LC_0027_RemoveElement {
    public int removeElement(int[] nums, int val) {
        int left = 0;
        int right = nums.length - 1;
        int removed = 0;

        while ( left <= right) {
            if (nums[right] == val) {
                right--;
            } else if (nums[left] == val) {
                nums[left] = nums[left] ^ nums[right];
                nums[right] = nums[left] ^ nums[right];
                nums[left] = nums[left] ^ nums[right];
                right--;
            } else {
                left++;
            }

        }
        return left;
    }
}
