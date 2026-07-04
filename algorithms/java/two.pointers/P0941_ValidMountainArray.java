// https://leetcode.com/problems/valid-mountain-array/

public class P0941_ValidMountainArray {
    public boolean validMountainArray(int[] arr) {
        if ( arr.length < 3) {
            return false;
        }

        boolean ascending = true;
        boolean descending = false;
        boolean peak = false;

        for (int i = 1; i < arr.length ; i++) {
            if (arr[i] < arr[i - 1]) {
                if ( i == 1) {
                    return false;
                }
                ascending = false;
                descending = true;
                peak = true;
            }
            if (ascending) {
                if (arr[i] <= arr[i - 1]) {
                    return false;
                }
            } else {
                if (arr[i] >= arr[i - 1]) {
                    return false;
                }
            }
        }
        return peak;
    }
}
