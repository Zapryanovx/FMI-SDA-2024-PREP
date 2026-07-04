// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/

public class LC_1588_SumOfAllOddLengthSubarrays {
    public int sumOddLengthSubarrays(int[] arr) {
        int[] prefix = new int[arr.length + 1];
        for (int i = 0; i < arr.length; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        int total = 0;
        for (int k = 1; k <= arr.length; k += 2) {
            for (int i = 0; i <= arr.length - k; i++) {
                total += prefix[i + k] - prefix[i];
            }
        }
        return total;
    }
}
