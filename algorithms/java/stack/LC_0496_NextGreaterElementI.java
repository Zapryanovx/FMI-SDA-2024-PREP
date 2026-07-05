// https://leetcode.com/problems/next-greater-element-i/description/

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class LC_0496_NextGreaterElementI {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> next = new HashMap<>();
        Deque<Integer> d = new ArrayDeque<>();

        for (int n: nums2) {
            while (!d.isEmpty() && n > d.peekLast()) {
                int el = d.pollLast();
                next.put(el, n);
            }
            d.add(n);
        }

        while (!d.isEmpty()) {
            next.put(d.pollLast(), -1);
        }

        int[] res = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            res[i] = next.get(nums1[i]);
        }
        return res;
    }
}
