// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
package backtracking;

public class LC_1863_SumOfAllSubsetXORTotals {
    public int subsetXORSum(int[] nums) {
        return backtrack(nums, 0, 0);
    }

    private int backtrack(int[] nums, int at, int sum) {
        if (at == nums.length) {
            return sum;
        }

        int include = backtrack(nums, at + 1, sum ^ nums[at]);
        int exclude = backtrack(nums, at + 1, sum);

        return include + exclude;
    }
}

