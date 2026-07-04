// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class LC_0448_FindAllNumbersDisappearedInAnArray {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        Set<Integer> unique = Arrays.stream(nums)
                .boxed()
                .collect(Collectors.toSet());

        List<Integer> l = new ArrayList<>();
        for (int i = 1; i <= nums.length; i++) {
            if (!unique.contains(i)) {
                l.add(i);
            }
        }

        return l;
    }
}
