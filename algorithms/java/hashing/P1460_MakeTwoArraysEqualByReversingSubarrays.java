// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/

import java.util.HashMap;
import java.util.Map;

public class P1460_MakeTwoArraysEqualByReversingSubarrays {
    public boolean canBeEqual(int[] target, int[] arr) {
        if (target.length != arr.length) {
            return false;
        }

        Map<Integer, Integer> cnts = new HashMap<>();

        for (int i = 0; i < target.length; i++) {
            cnts.put(target[i], cnts.getOrDefault(target[i], 0) + 1);
            cnts.put(arr[i], cnts.getOrDefault(arr[i], 0) - 1);
        }

        for (var entry: cnts.entrySet()) {
            if (entry.getValue() != 0) {
                return false;
            }
        }

        return true;
    }
}
